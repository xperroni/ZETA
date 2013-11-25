#include "indices.hpp"

zeta::Indices::Indices(const Parameters &p, const L &l) {
    size_t i = l[0];
    for (int j = 0, n = p.n_H; j < n; j++) {
        push_back(J(i, j));
    }
}
