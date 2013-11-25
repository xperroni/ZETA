#ifndef ZETA_EXTRACTOR_HPP
#define ZETA_EXTRACTOR_HPP

#include "parameters.hpp"

namespace zeta {
    class Extractor;
}

class zeta::Extractor {
    const Y &y;

public:
    Extractor(const Parameters &p, const Y &y);

    G operator () (const J &j) const;
};

#endif
