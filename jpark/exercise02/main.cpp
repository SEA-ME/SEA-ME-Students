#include "Converter.hpp"
#include <iostream>

int main(int argc, char **argv) {
		try {
				Converter converter(argc, argv);
				converter.convert();
				converter.printStr();
		} catch(std::exception &e) {
				std::cerr << e.what();
				return 1;
		}
		return 0;
}
