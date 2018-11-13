#ifndef DIVISION_HPP_
#define DIVISION_HPP_

#include "Operation.hpp"

class Division : public Operation {
public:
    Division()
    : Operation(OPID_Division)
    {
        operator_symbol_ = "/";
        number_generator_ = new NumberGenerator(1, 9);
        GenerateValues();
        PrepareRendering();
    }
    ~Division() {}
    void GenerateValues() {
        second_operand_ = number_generator_->Get();
        result_ = number_generator_->Get();
        first_operand_ = result_ * second_operand_;
    }
};

#endif // DIVISION_HPP_
