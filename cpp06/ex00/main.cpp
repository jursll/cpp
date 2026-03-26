#include "ScalarConverter.hpp"

int main(int ac, char** av) {
	if (ac == 2) {
		std::string arg = av[1];
		ScalarConverter::convert (arg);
	}
	else
		std::cerr << "args only needed : ./convert and a char, float, int or double" << std::endl;
}
