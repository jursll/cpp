#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Constructor for Presidential Pardon Form called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
AForm(src.getName(), src.getSGrade(), src.getEGrade()) {
	std::cout << "Copy constructor for Presidential Pardon Form called" << std::endl;
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	this->setSigned(src.getSigned());
	this->_target = src.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor for Presidential Pardon Form called" << std::endl;
}

const std::string PresidentialPardonForm::getTarget() const {
	return(this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == 0)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getEGrade())
		throw (AForm::GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
