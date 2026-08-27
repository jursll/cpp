#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	try
	{
		PmergeMe object(argc, argv);
			object.printContainerVector();
			object.sortVector();
			object.printTimeVector();
		PmergeMe object1(argc, argv);
			object1.sortDeque();
			object1.printTimeDeque();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
