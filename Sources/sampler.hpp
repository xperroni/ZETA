#ifndef ZETA_SAMPLER_HPP
#define ZETA_SAMPLER_HPP

#include "domain.hpp"
#include "parameters.hpp"

#include <stdexcept>

namespace zeta {
    template<class B> class Sampler;
}

template<class B> class zeta::Sampler {
    const Parameters &p;

    List<X> x;

public:
    Sampler(const Parameters &p, const X &x);

    B operator () (const L &l, const J &j) const;
};

template<class B> zeta::Sampler<B>::Sampler(const Parameters &_p, const X &_x):
    p(_p)
{
    cv::split(_x, x);

    cv::Mat hls;
    std::vector<cv::Mat> channels;
    cv::cvtColor(_x, hls, CV_BGR2HLS);
    cv::split(hls, channels);

    x.push_back(channels[1]);
}

template<class B> B zeta::Sampler<B>::operator () (const L &l, const J &j) const {
    B bits;
    int d = 0;
    cv::Rect roi(j[1] * p.n_P, j[0] * p.m_P, p.n_P, p.m_P);
    for (int k = 0, n = x.size(); k < n; k++) {
        S s(l[0], l[1], k);
        std::map<S, gaussian::sampler>::const_iterator si = p.synapses.find(s);
        if (si == p.synapses.end()) {
            throw std::runtime_error(std::string("No synapses found for index ") + (std::string) s);
        }

        const gaussian::sampler &sampler = si->second;
        cv::Mat c_k(x[k], roi);
        cv::Mat f_k = fourier::transform(c_k);
        cv::Mat p_k = fourier::magnitude(f_k);
        cv::Mat samples = sampler.sample<F>(p_k);
        d = vgram::minchinton<B, F>(bits, d, samples);
    }

    return bits;
}

#endif
