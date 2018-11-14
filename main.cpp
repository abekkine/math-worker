#include "OperationManager.hpp"

#include <iostream>

int main() {

    OperationManager opManager;

    try {
        opManager.Init();
        opManager.Run();
    }
    catch (std::string & eMsg) {
        std::cerr << "Application Error : " << eMsg << '\n';
    }
    catch (std::exception & e) {
        std::cerr << "System Error : " << e.what() << '\n';
    }

    return 0;
}
