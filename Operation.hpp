#ifndef OPERATION_H_
#define OPERATION_H_

#include "NumberGenerator.hpp"

#include <iostream>
#include <cstdint>
#include <string>

enum OperationIdentifier {
    OPID_BEGIN = 0,
    OPID_Addition = 0,
    OPID_Subtraction = 1,
    OPID_Multiplication = 2,
    OPID_Division = 3,
    OPID_END = 3,
};

enum QuestionType {
    QT_BEGIN = 0,
    QT_FirstOperand = 0,
    QT_SecondOperand = 1,
    QT_Result = 2,
    QT_Operator = 3,
    QT_END = 3,
};

class Operation {
public:
    Operation()
    : Operation(OPID_Addition)
    {}
    Operation(OperationIdentifier id)
    : id_(id)
    , type_generator_(NumberGenerator(QT_BEGIN, QT_END))
    {
        // GenerateValues();
        GenerateType();
    }
    virtual ~Operation() {}
    OperationIdentifier GetIdentifier() {
        return id_;
    }
    QuestionType GetType() {
        return type_;
    }
    int32_t GetResult() {
        return result_;
    }
    int32_t GetFirstOperand() {
        return first_operand_;
    }
    int32_t GetSecondOperand() {
        return second_operand_;
    }
    bool CheckAnswer(std::string answer) {
        bool isCorrect = false;
        if (type_ == QT_Operator) {
            isCorrect = (answer == operator_symbol_);
        } else {
            int value;
            try {
                value = std::stoi(answer);
                int number;
                switch (type_) {
                case QT_FirstOperand:
                    number = first_operand_;
                    break;
                case QT_SecondOperand:
                    number = second_operand_;
                    break;
                case QT_Result:
                    number = result_;
                    break;
                default:
                    throw std::string("Invalid question type!");
                    break;
                }
                isCorrect = (value == number);
            }
            catch (std::invalid_argument) {
                std::cerr << "Not a number!\n";
            }
        }
        return isCorrect;
    }
    void Render() {
        std::cout << question_text_ << '\n';
    }

public:
    virtual void GenerateValues() {}

protected:
    void GenerateType() {
        type_ = static_cast<QuestionType>(type_generator_.Get());
    }
    void PrepareRendering() {
        first_operand_text_ = std::to_string(first_operand_);
        second_operand_text_ = std::to_string(second_operand_);
        result_text_ = std::to_string(result_);
        operator_text_ = operator_symbol_;
        switch (type_) {
        case QT_FirstOperand:
            first_operand_text_= "?";
            break;
        case QT_SecondOperand:
            second_operand_text_ = "?";
            break;
        case QT_Operator:
            operator_text_ = "?";
            break;
        case QT_Result:
        default:
            result_text_ = "?";
            break;
        }

        question_text_  = first_operand_text_ + " ";
        question_text_ += operator_text_ + " ";
        question_text_ += second_operand_text_ + " = ";
        question_text_ += result_text_;
    }

protected:
    OperationIdentifier id_;
    QuestionType type_;
    int32_t first_operand_;
    int32_t second_operand_;
    int32_t result_;
    std::string operator_symbol_;
    std::string operator_text_;
    std::string first_operand_text_;
    std::string second_operand_text_;
    std::string result_text_;

private:
    std::string question_text_;
    NumberGenerator type_generator_;
};

#endif // OPERATION_H_
