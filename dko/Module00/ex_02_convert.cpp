#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>


using namespace std;

class CaseConverter {
public:
    static string toUpperCase(const string &str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    static string toLowerCase(const string &str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <up|down> <'string to convert'>" << endl;
        return 1;
    }
   
    string action(argv[1]);
    string input;

    // Join all remaining arguments into one string
    for (int i = 2; i < argc; ++i) {
        cout<<argv[i]<<endl;
        if (i > 2)
            input += " ";
        input += argv[i];
    }

    if (action == "up") {
        cout << CaseConverter::toUpperCase(input) << endl;
    } else if (action == "down") {
        cout << CaseConverter::toLowerCase(input) << endl;
    } else {
        cerr << "Unknown action: " << action << ". Please choose 'up' or 'down'." << endl;
        return 1;
    }

    return 0;
}
