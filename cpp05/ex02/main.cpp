#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
	{
		std::cout << "\033[92m\n---- Shrubbery Creation Form ----\033[0m" << std::endl;
		try {
			Bureaucrat b1("Julia", 1);
			Bureaucrat b2("Sophie", 150);
			ShrubberyCreationForm s1("SCF-ok");
			ShrubberyCreationForm s2("SCF-ko");
			std::cout << "\n" << b1 << std::endl;
			std::cout << s1 << std::endl;
			b1.signForm(s1);
			b1.executeForm(s1);

			std::cout << "\n" << b2 << std::endl;
			std::cout << s2 << std::endl;
			b2.signForm(s2);
			b2.executeForm(s2);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Robotomy Request Form ----\033[0m" << std::endl;
		try {
			Bureaucrat* b[10];
			RobotomyRequestForm* s[10];
			std::srand(std::time(NULL));
			for (int i = 0; i < 10; i++) {
				b[i] = new Bureaucrat("Julia", 1);
				s[i] = new RobotomyRequestForm("RRF-ok");
			}
			for (int i = 0; i < 10; i++) {
			std::cout << "\n" << i + 1 << std::endl;
			b[i]->signForm(*s[i]);
			b[i]->executeForm(*s[i]);
			}
			for (int i = 0; i < 10; i++) {
				delete b[i];
				delete s[i];
			}

			Bureaucrat b6("Sophie", 150);
			RobotomyRequestForm s6("RRF-ko");
			std::cout << "\n" << b6 << std::endl;
			std::cout << s6 << std::endl;
			b6.signForm(s6);
			b6.executeForm(s6);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[92m\n---- Presidential Pardon Form ----\033[0m" << std::endl;
		try {
			Bureaucrat b1("Julia", 1);
			Bureaucrat b2("Sophie", 1);
			PresidentialPardonForm s1("PPF-ok");
			PresidentialPardonForm s2("PPF-ko");
			std::cout << "\n" << b1 << std::endl;
			std::cout << s1 << std::endl;
			b1.signForm(s1);
			b1.executeForm(s1);

			std::cout << "\n" << b2 << std::endl;
			std::cout << s2 << std::endl;
			//b2.signForm(s2);
			b2.executeForm(s2);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
