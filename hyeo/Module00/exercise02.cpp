#include <iostream>
#include <string>

using namespace std;

string toUpperCase(const string& str)
{
    string result = str;

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] = toupper(result[i]);
        }
        else
        {
            continue;
        }
    }

    return result;
}

string toLowerCase(const string& str)
{
    string result = str;

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 'A' && result[i] <= 'Z')
        {
            result[i] = tolower(result[i]);
        }
        else
        {
            continue;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << "{command} {string}" << endl;
        return 1;
    }

    string command = argv[1];
    string inputStr;

    for (int i = 2; i < argc; ++i)
    {
        inputStr += argv[i];
        if (i< argc -1)
        {
            inputStr += " ";
        }
    }

    if (command == "up")
    {
        cout << toUpperCase(inputStr) << endl;
    }
    else if (command == "down")
    {
        cout << toLowerCase(inputStr) << endl;
    }
    else
    {
        cerr << "Invalid command. Use 'up' or 'down'." << endl;
        return 1;
    }

    return 0;
}