#ifndef MULTIPLICATION_HPP_
#define MULTIPLICATION_HPP_

#include "Operation.hpp"

class Multiplication : public Operation {
public:
    Multiplication()
    : Operation(OPID_Multiplication)
    {
        operator_symbol_ = "x";
        number_generator_ = new NumberGenerator(0, 9);
        GenerateValues();
        PrepareRendering();
    }
    ~Multiplication() {}
    void GenerateValues() {
        first_operand_ = number_generator_->Get();
        second_operand_ = number_generator_->Get();
        result_ = first_operand_ * second_operand_;
    }
};

#endif // MULTIPLICATION_HPP_
