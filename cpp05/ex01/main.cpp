#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\033[92m\n---- Everything valid ----\033[0m" << std::endl;
		try {
			Bureaucrat b("Sophie", 100);
			std::cout << b << std::endl;
			Form f("Form", 150, 150);
			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Bureaucrat valid\033[91m but Grade too low to sign ----\033[0m" << std::endl;
		try {
			Bureaucrat b("Sophie", 100);
			std::cout << b << std::endl;
			Form f("Form", 10, 150);
			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[91m\n---- Form invalid (grade to sign too high) ----\033[0m" << std::endl;
		try {
			Form f;
			std::cout << f << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[91m\n---- Form invalid (grade to execute too low) ----\033[0m" << std::endl;
		try {
			Form f("Form", 100, 151);
			std::cout << f << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Create Form then try to change values with assignment operator ----\033[0m" << std::endl;
		try {
			Form f1("Form1", 100, 10);
			Form f2;
			std::cout << f1 << std::endl;
			std::cout << f2 << std::endl;

			f2 = f1;
			std::cout << f2 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Sign form already signed ----\033[0m" << std::endl;
		try {
			Bureaucrat b("Sophie", 100);
			std::cout << b << std::endl;
			Form f("Form", 150, 150);
			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.signForm(f);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
