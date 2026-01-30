#include "Bureaucrat.hpp"

int main()
{
	/*std::cout << "---- Valid construction + valid increment ----" << std::endl;
	try {
	Bureaucrat a("Julia", 150);
	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---- Assignment operator ----" << std::endl;
	try {
	Bureaucrat a("Julia", 20);
	Bureaucrat b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b = a;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}*/

	std::cout << "---- Copy constructor ----" << std::endl;
	try {
	Bureaucrat a("Julia", 20);
	std::cout << a << std::endl;
	Bureaucrat b(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
