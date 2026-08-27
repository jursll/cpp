#include "RPN.hpp"
#include <iostream>

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	RPN calculator;
	int result;

	if (!calculator.evaluate(av[1], result))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::cout << result << std::endl;

	return (0);
}
