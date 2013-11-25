#include "extractor.hpp"

zeta::Extractor::Extractor(const Parameters &_p, const Y &_y):
    y(_y)
{
    // Nothing to do.
}

zeta::G zeta::Extractor::operator () (const J &j) const {
    return y.at<G>(j[0], j[1]);
}
