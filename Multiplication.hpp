#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

class Multiplication : public Operation {
public:
    Multiplication()
    : Operation(OPID_Multiplication)
    , number_generator_(0)
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

private:
    NumberGenerator * number_generator_;
};

#endif // MULTIPLICATION_H_
