#ifndef ZETA_ASSEMBLER_TOP_10_HPP
#define ZETA_ASSEMBLER_TOP_10_HPP

#include "output.hpp"
#include "parameters.hpp"

namespace zeta {
    class AssemblerTop10;
}

class zeta::AssemblerTop10 {
    const Parameters &p;

    List<cv::Mat> depths;

    List<cv::Mat> errors;

public:
    AssemblerTop10(const Parameters &p);

    void add(const L &l, const J &j, const G &g, size_t d);

    Output operator () () const;
};

#endif
