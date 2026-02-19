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

int Form::getSGrade() const {
	return this->_sgrade;
}

int Form::getEGrade() const {
	return this->_egrade;
}

void Form::beSigned(Bureaucrat &src) {
	if (src.getGrade() <= this->_sgrade && this->getSigned() == 0)
		this->_signed = true;
	else if (src.getGrade() <= this->_sgrade && this->getSigned() == 1)
		throw(Form::FormAlreadySignedException());
	else
		throw (Form::GradeTooLowException());
}

std::ostream & operator<<(std::ostream & ostr, Form const & src) {
	ostr << "Form name: " << src.getName() << std::endl;
	ostr << "Signed (1 = true, 0 = false): " << src.getSigned() << std::endl;
	ostr << "Grade to signe must be > " << src.getSGrade() << std::endl;
	ostr << "Grade to execute must be > " << src.getEGrade() << std::endl;
	return (ostr);
}
