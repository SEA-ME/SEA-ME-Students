#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac < 3)
        std::cout << "Invalid number of arguments" << std::endl;
    else {
        // I want upper case converter also lower case converter
        // It also used './converter up hello world -> HELLO WORLD'
        // It also used './converter down HELLO WOrLD! -> hello world!'
        std::string str;
        for (int i = 2; i < ac; i++) {
            str += av[i];
            if (i != ac - 1)
            str += " ";
        }
        if (std::string(av[1]) == "up") {
            for (size_t i = 0; i < str.length(); i++)
            {
                str[i] = toupper(str[i]);
                std::cout << str[i];
            }
        } else if (std::string(av[1]) == "down") {
            for (size_t i = 0; i < str.length(); i++)
            {
                str[i] = tolower(str[i]);
                std::cout << str[i];
            }
        } else {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
    }
}
