#ifndef ZETA_PARAMETERS_HPP
#define ZETA_PARAMETERS_HPP

#include "domain.hpp"

#include <map>

namespace zeta {
    struct Parameters;
}

struct zeta::Parameters {
    const int m_N;

    const int n_N;

    const int m_H;

    const int n_H;

    const int m_P;

    const int n_P;

    std::map<S, gaussian::sampler> synapses;

    Parameters(int length, int samples, double sigma, const cv::Size &images, const cv::Size &depths);
};

#endif
