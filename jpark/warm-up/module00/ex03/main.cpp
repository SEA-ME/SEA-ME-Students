#include <iostream>
#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook;
	std::string	input;

	while (true) {
        std::cout << "type a command > ";
        std::getline(std::cin, input);

        if (input == "ADD") {
			phonebook.add();
        } else if (input == "SEARCH") {
			phonebook.search();
        } else if (input == "REMOVE") {
            phonebook.remove();
        } else if (input == "BOOKMARK") {
            phonebook.bookmark();
        } else if (input == "EXIT") {
			break ;
        } else if (std::cin.eof() == true) {
            std::cout << std::endl;
			break ;
        } else if (input == "\0") {
			continue ;
        } else {
			phonebook.printError(INVALID_COMMAND);
        }
	}
	return 0;
}
