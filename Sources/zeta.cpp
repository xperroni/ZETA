#include "cases.hpp"

int main(int argc, char *argv[]) {
/*    dither_image(
        "/home/helio/Documents/Yamabiko/2013-2/Weightless Neural Networks for Depth estimation/References",
        "statroad4-p-77t0",
        "jpg"
    );

    depth_map_plot(
        "/home/helio/Documents/Yamabiko/2013-2/Weightless Neural Networks for Depth estimation/References",
        "statroad2-p-282t0",
        "png",
        cv::Size(86, 107),
        cv::Size(1704, 2272)
    );
*/
//    disassemble_sample("/home/helio/Documents", "patch", "png");
    train_and_test(argv[1], argv[2]);
/*    train_and_test(
        "/home/helio/Projects/Data/Saxena/once.txt",
        "/home/helio/Projects/Data/Saxena/once.txt"
    );
*/
    return 0;
}
