#ifndef ZETA_ASSEMBLER_HPP
#define ZETA_ASSEMBLER_HPP

#include "output.hpp"
#include "parameters.hpp"

namespace zeta {
    class Assembler;
}

class zeta::Assembler {
    const Parameters &p;

    List<cv::Mat> depths;

    List<cv::Mat> errors;

public:
    Assembler(const Parameters &p);

    void add(const L &l, const J &j, const G &g, size_t d);

    Output operator () () const;
};

#endif
