#include "Operation.hpp"
#include "Addition.hpp"
#include "Subtraction.hpp"
#include "Multiplication.hpp"
#include "Division.hpp"
#include "OperationLog.hpp"
#include "UserStats.hpp"
#include "UserRecord.hpp"
#include "NumberGenerator.hpp"

#include <iostream>

void getAnswer(std::string & answer) {

    answer = std::string();

    std::cout << "Enter your answer : ";
    std::cin >> answer;
}

int getUserId() {
    return 1;
}

Operation * getRandomQuestion() {

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

int main() {

    bool quit = false;
    Operation * op = 0;

    OperationLog log;

    int user_id = getUserId();
    UserStats stats(user_id);
    stats.GetRecords();

    std::string answer;

    while (! quit) {
        op = getRandomQuestion();
        op->Render();
        getAnswer(answer);
        if (answer[0] != 'q') {
            if (op->CheckAnswer(answer)) {
                // Answer is correct.
                std::cout << "Correct!\n";
            } else {
                // Answer is incorrect.
                std::cout << "Incorrect!\n";
                // Show correct solution :
                op->ShowAnswer();
                // Log operation details.
                log.AddLogLine(user_id, answer, op);
            }
        }
        else {
            quit = true;
        }
    }

    return 0;
}
