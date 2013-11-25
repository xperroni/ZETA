#include "zeta.hpp"

void train_and_test(const std::string &train, const std::string &test) {
    zeta::ZETA<256> z(10, 4.0, cv::Size(1704, 2272), cv::Size(86, 107));
    z.train(train);
    z.test(test);
}

int main(int argc, char *argv[]) {
   train_and_test(argv[1], argv[2]);
/*    train_and_test(
        "/home/helio/Projects/Data/Saxena/dummy_train.txt",
        "/home/helio/Projects/Data/Saxena/dummy_test.txt"
    );*/

    return 0;
}
