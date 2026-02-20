#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "\033[92m\n---- Shrubbery Creation Form ----\033[0m" << std::endl;
		try {
			Bureaucrat b = Bureaucrat("Julia", 1);
			ShrubberyCreationForm s = ShrubberyCreationForm("SCF");
			std::cout << b << std::endl;
			std::cout << s << std::endl;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

}
