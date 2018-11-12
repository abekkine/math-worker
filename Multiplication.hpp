#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

class Multiplication : public Operation {
public:
    Multiplication()
    : Operation(OPID_Multiplication)
    {
        operator_text_ = "x";
    }
    ~Multiplication() {}
    void GenerateValues() {

    }
};

#endif // MULTIPLICATION_H_
