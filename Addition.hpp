#ifndef ADDITION_H_
#define ADDITION_H_

class Addition : public Operation {
public:
    Addition()
    : Operation(OPID_Addition)
    , number_generator_(0)
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

private:
    NumberGenerator * number_generator_;
};

#endif // ADDITION_H_
