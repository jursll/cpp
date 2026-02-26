#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		std::cout << "\033[92m\n---- Correct tests ----\033[0m" << std::endl;
		try {
			Intern Jimmy;
			AForm *form = Jimmy.makeForm("robotomy request", "Bender");
			if (form)
			{
				std::cout << *form << std::endl;
				delete form;
			}
		}
		catch(const std::exception& e) {
			std:: cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "\033[91m\n---- Wrong tests ----\033[0m" << std::endl;
		try {
			Intern Jimmy;
			AForm *form = Jimmy.makeForm("wrong form name", "Bender");
			if (form)
			{
				std::cout << *form << std::endl;
				delete form;
			}
		}
		catch(const std::exception& e) {
			std:: cerr << e.what() << std::endl;
		}
	}
}
