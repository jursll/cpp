#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Constructor for Cat called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &src) {
	std::cout << "Copy constructor for Cat called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &src) {
	this->_type = src._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Destructor for Cat called" << std::endl;
}
