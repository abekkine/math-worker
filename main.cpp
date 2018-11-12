#include "Operation.hpp"
#include "Addition.hpp"
#include "OperationLog.hpp"
#include "UserStats.hpp"
#include "UserRecord.hpp"

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

    return new Addition();
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
        if (op->CheckAnswer(answer)) {
            // Answer is correct.
            std::cout << "Correct!\n";
        } else {
            // Answer is incorrect.
            std::cout << "Incorrect!\n";
            // Log operation details.
            log.AddLogLine(user_id, answer, op);
        }
    }

    return 0;
}
