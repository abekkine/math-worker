#ifndef OPERATION_MANAGER_HPP_
#define OPERATION_MANAGER_HPP_

#include "Operation.hpp"
#include "Addition.hpp"
#include "Subtraction.hpp"
#include "Multiplication.hpp"
#include "Division.hpp"
#include "OperationLog.hpp"
#include "UserStats.hpp"

#include <string>

class OperationManager {
public:
    OperationManager() {}
    ~OperationManager() {}
    void Init() {
        quit_ = false;
        user_id_ = GetUserId();
        stats_ = new UserStats(user_id_);
        stats_->GetRecords();
    }

    void Run() {

        Operation * op = 0;
        std::string answer;

        while (! quit_) {
            op = GetRandomQuestion();
            op->Render();
            GetAnswer(answer);
            if (answer[0] != 'q') {
                if (op->CheckAnswer(answer)) {
                    // Answer is correct
                    std::cout << "Correct!\n";
                }
                else {
                    // Answer is incorrect
                    std::cout << "Incorrect!\n";
                    // Show correct solution
                    op->ShowAnswer();
                    // Log operation details.
                    log_.AddLogLine(user_id_, answer, op);
                }
            }
            else {
                quit_ = true;
            }
        }
    }

private:
    void GetAnswer(std::string & answer) {
        answer = std::string();
    
        std::cout << "Enter your answer : ";
        std::cin >> answer;
    }

    int GetUserId() {
        // TODO
        return 1;
    }

    Operation * GetRandomQuestion() {

        NumberGenerator gen(OPID_BEGIN, OPID_END);
        Operation * op = 0;
    
        OperationIdentifier operation_id = static_cast<OperationIdentifier>(gen.Get());
        switch(operation_id) {
        case OPID_Addition:
            op = new Addition();
            break;
    
        case OPID_Subtraction:
            op = new Subtraction();
            break;
    
        case OPID_Division:
            op = new Division();
            break;
    
        case OPID_Multiplication:
            op = new Multiplication();
            break;
    
        default:
            throw std::string("Invalid operation identifier!");
            break;
        }
    
        return op;
    }

private:
    bool quit_;
    int user_id_;
    UserStats * stats_;
    OperationLog log_;
};

#endif // OPERATION_MANAGER_HPP_

