#ifndef ZETA_NEURONS_HPP
#define ZETA_NEURONS_HPP

#include "parameters.hpp"

namespace zeta {
    template<class B> class Neurons;
}

template<class B> class zeta::Neurons: public std::map<L, vgram::neuron<B, G> > {
public:
    Neurons();

    Neurons(const Parameters &p, Neurons &N_z, const X &x);

    Neurons(const Parameters &p, const Neurons &N_z, const X &x);
};

template<class B> zeta::Neurons<B>::Neurons() {
    // Nothing to do.
}

template<class B> zeta::Neurons<B>::Neurons(const Parameters &p, Neurons &N_z, const X &x) {
    for (int i = 0, m = p.m_N; i < m; i++) {
        for (int j = 0, n = p.n_N; j < n; j++) {
            L l(i, j);
            (*this)[l] = N_z[l];
        }
    }
}

template<class B> zeta::Neurons<B>::Neurons(const Parameters &p, const Neurons &N_z, const X &x) {
    for (int i = 0, m = p.m_N; i < m; i++) {
        for (int j = 0, n = p.n_N; j < n; j++) {
            L l(i, j);
            if (N_z.count(l) > 0) {
                (*this)[l] = N_z.find(l)->second;
            }
        }
    }
}

#endif
