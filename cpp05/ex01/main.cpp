#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n---- Valid init + valid increment ----" << std::endl;
		try {
		Bureaucrat a("Julia", 150);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n---- Invalid init ----" << std::endl;
		try {
		Bureaucrat a("Julia", 200);
		std::cout << a << std::endl;
//		a.incrementGrade();
//		std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n---- Valid init + invalid decrement ----" << std::endl;
		try {
		Bureaucrat a("Julia", 150);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n---- Valid init + invalid increment ----" << std::endl;
		try {
		Bureaucrat a("Julia", 1);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
