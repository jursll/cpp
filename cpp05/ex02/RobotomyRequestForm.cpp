#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Constructor for Robotomy Request Form called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
AForm(src.getName(), src.getSGrade(), src.getEGrade()) {
	std::cout << "Copy constructor for Robotomy Request Form called" << std::endl;
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	this->setSigned(src.getSigned());
	this->_target = src.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor for Robotomy Request Form called" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const {
	return(this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == 0)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getEGrade())
		throw (AForm::GradeTooLowException());
	std::cout << "*Drilling noses*" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized (successful 50% of the time)" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
