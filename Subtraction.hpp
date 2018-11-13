#ifndef SUBTRACTION_HPP_
#define SUBTRACTION_HPP_

#include "Operation.hpp"

class Subtraction : public Operation {
public:
    Subtraction()
    : Operation(OPID_Subtraction)
    {
        operator_symbol_ = "-";
        number_generator_ = new NumberGenerator(0, 9);
        GenerateValues();
        PrepareRendering();
    }
    ~Subtraction() {}
    void GenerateValues() {
        second_operand_ = number_generator_->Get();
        result_ = number_generator_->Get();
        first_operand_ = result_ + second_operand_;
    }
};

#endif // SUBTRACTION_HPP_
