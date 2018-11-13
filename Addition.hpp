#ifndef ADDITION_HPP_
#define ADDITION_HPP_

#include "Operation.hpp"

class Addition : public Operation {
public:
    Addition()
    : Operation(OPID_Addition)
    {
        operator_symbol_ = "+";
        number_generator_ = new NumberGenerator(0, 9);
        GenerateValues();
        PrepareRendering();
    }
    ~Addition() {}
    void GenerateValues() {
        first_operand_ = number_generator_->Get();
        second_operand_ = number_generator_->Get();
        result_ = first_operand_ + second_operand_;
    }
};

#endif // ADDITION_HPP_
