#include <iostream>
#include <cstring>
#include "case_converter.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <up|down> <'string to convert'>" << std::endl;
        return 1;
    }

    std::string action(argv[1]);
    std::string input;

    for (int i = 2; i < argc; ++i) {
        if (i > 2)
            input += " ";
        input += argv[i];
    }

    if (action == "up") {
        std::cout << CaseConverter::toUpperCase(input) << std::endl;
    } else if (action == "down") {
        std::cout << CaseConverter::toLowerCase(input) << std::endl;
    } else {
        std::cerr << "Unknown action: " << action << ". Please choose 'up' or 'down'." << std::endl;
        return 1;
    }

    return 0;
}
