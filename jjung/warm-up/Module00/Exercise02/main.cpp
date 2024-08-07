#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function Declaration
string convert(bool, string);

int main(int argc, char** argv)
{
    string upDown(argv[1]); // Convert First Argument from char* to string
    string text;            // Will Combine the Others Arguments from char* to string

    // Combine the Others Arguments
    for(int i = 2; i < argc; i++)
    {
        if(i > 2)
            text += " ";
        text += argv[i];
    }

    // Convert the Text by Using 'convert' Function
    string converted_text = convert(upDown == "up", text);

    // Print the Converted Text
    cout << converted_text << endl;

    return 0;
}

// Function Definition
string convert(bool isUpper, string text)
{
    // If First Argument is 'up'
    if(isUpper)
        for(char& c : text)
            c = char(toupper(c));

    // If Second Argument is 'down'
    else
        for(char& c : text)
            c = char(tolower(c));

    // Return the Converted Text
    return text;
}
