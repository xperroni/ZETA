#ifndef ZETA_NEURONS_HPP
#define ZETA_NEURONS_HPP

#include "parameters.hpp"

namespace zeta {
    template<class B> class Neurons;
}

template<class B> class zeta::Neurons: public std::map<L, vgram::neuron<B, G> > {
public:
    Neurons();

    Neurons(const Parameters &p, Neurons &N_z, const F &f, const G &g, const J &j);

    Neurons(const Parameters &p, const Neurons &N_z, const F &f, const J &j);
};

template<class B> zeta::Neurons<B>::Neurons() {
    // Nothing to do.
}

template<class B> zeta::Neurons<B>::Neurons(
    const Parameters &p,
    Neurons &N_z,
    const F &f,
    const G &g,
    const J &j
) {
    static cv::RNG rng;

    size_t i = j[0];
    size_t range = p.n_N;
    for (int j = 0, n = range / 10; j < n; j++) {
        L l(i, rng(range));
        (*this)[l] = N_z[l];
    }
}

template<class B> zeta::Neurons<B>::Neurons(
    const Parameters &p,
    const Neurons &N_z,
    const F &f,
    const J &j
) {
    size_t i = j[0];
    typename Neurons::const_iterator z = N_z.end();
    for (int j = 0, n = p.n_N; j < n; j++) {
        L l(i, j);
        typename Neurons::const_iterator nl = N_z.find(l);
        if (nl != z) {
            (*this)[l] = nl->second;
        }
    }
}

#endif
