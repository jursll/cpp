#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Constuctor for Wrong Animal called" << std::endl;
	this->_type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "Copy constructor for Wrong Animal called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	this->_type = src._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor for Wrong Animal called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Random wrong animal sound ..." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}
