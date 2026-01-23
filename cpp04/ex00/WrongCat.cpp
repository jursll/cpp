#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Constructor for Wrong Cat called" << std::endl;
	this->_type = "Wrong Cat";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "Copy constructor for Wrong Cat called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
	this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Destructor for Wrong Cat called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Miaou miaou" << std::endl;
}
