#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "Constuctor for AAnimal called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "Copy constructor for AAnimal called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
	this->_type = src._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "Destructor for AAnimal called" << std::endl;
}

std::string AAnimal::getType() const {
	return (this->_type);
}
