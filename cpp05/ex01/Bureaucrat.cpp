#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Random"), _grade(150) {
	std::cout << "Constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Constructor for Bureaucrat called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name) {
	std::cout << "Copy constructor for Bureaucrat called" << std::endl;
	this->_grade = src._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor for Bureaucrat called" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade += 1;
}

std::ostream& operator<<(std::ostream& ostr, Bureaucrat const& src) {
	ostr << src.getName() << ", Bureaucrat grade " << src.getGrade();
	return ostr;
}
