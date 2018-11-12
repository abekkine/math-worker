#ifndef OPERATION_LOG_H_
#define OPERATION_LOG_H_

class OperationLog {
public:
    OperationLog() {}
    ~OperationLog() {}
    void AddLogLine(int user_id, std::string user_answer, Operation * op) {
        uint32_t time_stamp = 0; // TODO
        std::cout << "LOG : ";
        std::cout << time_stamp << ", ";
        std::cout << user_id << ", ";
        std::cout << op->GetIdentifier() << ", ";
        std::cout << op->GetType() << ", ";
        std::cout << user_answer << ", ";
        std::cout << op->GetFirstOperand() << ", ";
        std::cout << op->GetSecondOperand() << ", ";
        std::cout << op->GetResult() << '\n';
    }

    // Record format :
    // Timestamp, User, OperationIdentifier, QuestionType, UserAnswer, FirstOperand, SecondOperand, Result
};

#endif // OPERATION_LOG_H_
