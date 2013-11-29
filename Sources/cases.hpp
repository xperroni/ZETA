#ifndef ZETA_CASES_HPP
#define ZETA_CASES_HPP

#include "zeta.hpp"

#include <string>

void depth_map_plot(
    const std::string &folder,
    const std::string &name,
    const std::string &ext,
    const cv::Size &size,
    const cv::Size &scale
);

void dither_image(const std::string &folder, const std::string &name, const std::string &ext);

void disassemble_sample(const std::string &folder, const std::string &name, const std::string &ext);

void train_and_test(const std::string &train, const std::string &test);

#endif
