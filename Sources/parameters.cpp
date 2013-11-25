#include "parameters.hpp"

#define CHANNELS 4

zeta::Parameters::Parameters(
    int length,
    int samples,
    double sigma,
    const cv::Size &images,
    const cv::Size &depths
):
    m_N(depths.height),
    n_N(samples),
    m_H(depths.height),
    n_H(depths.width),
    m_P(images.height / m_H),
    n_P(images.width / n_H)
{
    cv::Size field(n_P, m_P);
    for (int i = 0; i < m_N; i++) {
        for (int j = 0; j < n_N; j++) {
            for (int k = 0; k < CHANNELS; k++) {
                synapses[S(i, j, k)] = gaussian::sampler(length / CHANNELS, sigma, field);
            }
        }
    }
}
