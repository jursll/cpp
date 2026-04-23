#include "iter.hpp"

int main() {
	std::cout << "Array of int: ";
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Const array of int: ";
	const int constIntArray[] = {6, 7, 8, 9, 10};
	iter(constIntArray, 5, printElement<const int>);
	std::cout << std::endl;

	std::cout << "Array of double: ";
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	std::cout << "Array of string: ";
	std::string stringArray[] = {"Hello", "World", "I", "am", "Julia"};
	iter(stringArray, 5, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
