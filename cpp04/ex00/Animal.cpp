#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Constuctor for Animal called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(Animal const &src) {
	std::cout << "Copy constructor for Animal called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	this->_type = src._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Destructor for Animal called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Random animal sound ..." << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}
