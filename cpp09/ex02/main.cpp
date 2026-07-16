#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "\033[1;31mProgram takes >1 positive integers\033[0m" << std::endl;
		return 1;
	}
	PmergeMe pmergeMe(argc, argv);
	(void)pmergeMe;
}
