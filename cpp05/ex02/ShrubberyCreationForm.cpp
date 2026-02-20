#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Constructor for Shrubbey Creation Form called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
AForm(src.getName(), src.getSGrade(), src.getEGrade()) {
	std::cout << "Copy constructor for Shrubbery Creation Form called" << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	this->setSigned(src.getSigned());
	this->_target = src.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor for Shrubbery Creation Form called" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return(this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == 0)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getEGrade())
		throw (AForm::GradeTooLowException());
	std::string file_name = this->getTarget() + "_shrubbery";
	std::ofstream File(file_name.c_str());
	File << TREE << std::endl;
	File.close();
}
