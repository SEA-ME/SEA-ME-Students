#include <iostream>
#include "Converter.hpp"

Converter::Converter(int argc, char** argv) {
		if (argc < 2) {
				throw ArgcException();
		}

		this->cmd = std::string(argv[1]);

		if (this->cmd != "up" && this->cmd != "down") {
				throw WrongCmdException();
		}

		for (int i = 2; i < argc; i++) {
				this->str.append(std::string(argv[i]));
				if (i < argc - 1) {
					this->str.append(1, ' ');
				}
		}
}

Converter::~Converter() {}

void Converter::convert() {
		std::string::iterator it = this->str.begin();
		std::string::iterator end = this->str.end();
		int offset = 'A' - 'a';

		if (this->cmd == "up") {
				while (it != end) {
						if (*it >= 'a' && *it <= 'z') {
							*it += offset;
						}
						it++;
				}
		} else {
				while (it != end) {
						if (*it >= 'A' && *it <= 'Z') {
								*it -= offset;
						}
						it++;
				}
		}
}

void Converter::printStr() {
	std::cout << this->str << '\n';
}

const char* Converter::ArgcException::what() const throw() {
		return "You need to put at least 2 arguments.\n./convert [up/down] [string]\n";
}

const char* Converter::WrongCmdException::what() const throw() {
		return "Command must be up or down.\n";
}
