#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &src);
		~Intern();

		AForm* makeSCF(std::string target) const;
		AForm* makeRRF(std::string target) const;
		AForm* makePPF(std::string target) const;

		AForm* makeForm(std::string formName, std::string target) const;

		class WrongFormException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Provided form name does not exist");
				}
		};
};

#endif
