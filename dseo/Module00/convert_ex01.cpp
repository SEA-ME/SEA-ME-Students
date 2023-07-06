#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>

class CaseConverter {
public:
    // Upper
    static std::string toUpperCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    // Lower
    static std::string toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        // Use cerr to find out error
        std::cerr << "Usage: " << argv[0] << " <up|down> <'string to convert'>" << std::endl;
        return 1;
    }

    std::string action(argv[1]);
    std::string input;

    // Join all remaining arguments into one string
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
