#ifndef ZETA_OUTPUT_HPP
#define ZETA_OUTPUT_HPP

#include "domain.hpp"

#include <boost/shared_ptr.hpp>

namespace zeta {
    class Output;
}

class zeta::Output {
    boost::shared_ptr<Y> y;

    size_t d;

public:
    Output(boost::shared_ptr<Y> &y, size_t d);

    const Y &output() const;

    size_t distance() const;
};

#endif
