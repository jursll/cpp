#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Constructor for Dog called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Copy constructor for Dog called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &src) {
	this->_type = src._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor for Dog called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Waf Waf" << std::endl;
}
