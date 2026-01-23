#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Constructor for Dog called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Copy constructor for Dog called" << std::endl;
	this->_brain = new Brain(*(src._brain)); // Copy the Brain
}

Dog &Dog::operator=(Dog const &src) {
	if (this != &src) {
		Animal::operator=(src); // Call the base class's operator=
		delete _brain; // Release existing brain resources
		_brain = new Brain(*(src._brain)); // Copy the Brain
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor for Dog called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const {
	std::cout << "Waf Waf" << std::endl;
}

void	Dog::setType(std::string newType) {
	this->_type = newType;
}

Brain* Dog::getBrain() const {
	return _brain;
}
