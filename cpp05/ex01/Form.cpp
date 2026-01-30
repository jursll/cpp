#include "Form.hpp"

Form::Form() : _name("Random"), _signed(false), _sgrade(150), _egrade(150) {
	std::cout << "Constructor for Form called" << std::endl;
}

Form::Form(const std::string name, const int sgrade, const int egrade) : _name(name), _signed(false), _sgrade(sgrade), _egrade(egrade) {
	std::cout << "Constructor for Form called" << std::endl;
	if (sgrade < 1 || egrade < 1 )
		throw Form::GradeTooHighException();
	if (sgrade > 150 || egrade > 150 )
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _sgrade(src._sgrade), _egrade(src._egrade) {
	std::cout << "Copy constructor for Form called" << std::endl;
	this->_signed = src._signed;
}

Form &Form::operator=(Form const &src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return(*this);
}

Form::~Form() {
	std::cout << "Destructor for Form called" << std::endl;
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

const int Form::getSGrade() const {
	return this->_sgrade;
}

const int Form::getEGrade() const {
	return this->_sgrade;
}

// TO CONTINUE : void beSigned(Bureaucrat &src);
