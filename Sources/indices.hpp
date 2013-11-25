#ifndef ZETA_INDICES_HPP
#define ZETA_INDICES_HPP

#include "parameters.hpp"

namespace zeta {
    class Indices;
}

class zeta::Indices: public List<J> {
public:
    Indices(const Parameters &p, const L &l);
};

#endif
