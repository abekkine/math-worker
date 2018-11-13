#ifndef NUMBER_GENERATOR_HPP_
#define NUMBER_GENERATOR_HPP_

#include <random>

class NumberGenerator {
public:
    explicit NumberGenerator(int a, int b)
    : min_value_(a)
    , max_value_(b)
    , distribution_min_max_(min_value_, max_value_)
    {}
    explicit NumberGenerator(int a)
    : NumberGenerator(0, a)
    {}
    ~NumberGenerator() {}
    int Get() {
        static std::random_device source;
        static std::mt19937 random_generator(source());
        int value = distribution_min_max_(random_generator);
        return value;
    }

private:
    int min_value_;
    int max_value_;
    std::uniform_int_distribution<int> distribution_min_max_;
};

#endif // NUMBER_GENERATOR_HPP_
