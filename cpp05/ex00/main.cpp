#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\033[92m\n---- Valid init + valid increment ----\033[0m" << std::endl;
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
		std::cout << "\033[91m\n---- Invalid init ----\033[0m" << std::endl;
		try {
			Bureaucrat a("Julia", 200);
			std::cout << a << std::endl;
//			a.incrementGrade();
//			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Valid init \033[0m+ \033[91minvalid decrement ----\033[0m" << std::endl;
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
		std::cout << "\033[92m\n---- Valid init \033[0m+ \033[91minvalid increment ----\033[0m" << std::endl;
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
