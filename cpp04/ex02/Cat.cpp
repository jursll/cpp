#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Constructor for Cat called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal(src) {
	std::cout << "Copy constructor for Cat called" << std::endl;
	this->_brain = new Brain(*(src._brain)); // Copy the Brain
}

Cat &Cat::operator=(Cat const &src) {
	if (this != &src) {
		AAnimal::operator=(src); // Call the base class's operator=
		delete _brain; // Release existing brain resources
		_brain = new Brain(*(src._brain)); // Copy the Brain
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Destructor for Cat called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const {
	std::cout << "Miaou miaou" << std::endl;
}

void Cat::setType(std::string newType) {
	this->_type = newType;
}

Brain* Cat::getBrain() const {
	return _brain;
}
