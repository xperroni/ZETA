#ifndef ZETA_CHANNELS_HPP
#define ZETA_CHANNELS_HPP

#include "parameters.hpp"

namespace zeta {
    const int CHANNELS = 4;

    class Channels;
}

class zeta::Channels {
    List<cv::Mat> x;

    List<J> x_j;

protected:
    const size_t side;

public:
    Channels(const Parameters &p, const X &x);

    F operator () (const J &j) const;

    const cv::Mat &channel(size_t i);

    const List<J> &indices();
};

#endif
