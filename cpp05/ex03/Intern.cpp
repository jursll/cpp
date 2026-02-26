#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Constructor for Intern called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Copy constructor for Intern called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const &src) {
	(void) src;
	return *this;
}

Intern::~Intern() {
	std::cout << "Destructor for Intern called" << std::endl;
}

AForm* Intern::makeSCF(std::string target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRRF(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePPF(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) const {
	AForm* newForm = NULL;

	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*ptr_to_function[])(std::string) const = {&Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			newForm = (this->*ptr_to_function[i])(target);
			break ;
		}
	}
	if (!newForm)
		throw(Intern::WrongFormException());
	return newForm;
}
