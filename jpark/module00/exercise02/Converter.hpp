#include <string>
#include <exception>

class Converter {
		private:
			std::string cmd;
			std::string str;

		public:
			Converter(int argc, char** argv);
			~Converter();
			
			void convert();
			void printStr();

		class ArgcException : public std::exception {
				public:
						const char* what() const throw();
		};

		class WrongCmdException : public std::exception {
				public:
						const char* what() const throw();
		};
};
