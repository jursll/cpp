#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "> Testing with DEBUG:" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n>Testing with INFO:" << std::endl;
	harl.complain("INFO");

	std::cout << "\n>Testing with WARNING:" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n>Testing with ERROR:" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n>Testing with something else:" << std::endl;
	harl.complain("something else");

	return 0;
}
