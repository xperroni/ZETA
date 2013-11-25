#include "output.hpp"

zeta::Output::Output(boost::shared_ptr<Y> &_y, size_t _d):
    y(_y),
    d(_d)
{
    // Nothing to do.
}

const zeta::Y &zeta::Output::output() const {
    return *y;
}

size_t zeta::Output::distance() const {
    return d;
}
