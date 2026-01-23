#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Constructor for Brain called" << std::endl;
}

Brain::Brain(Brain const &src) {
	std::cout << "Copy constructor for Brain called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &src) {
	for (int i = 0; i < 100; ++i) {
		(this->_ideas)[i] = src.getIdea(i);
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Destructor for Brain called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index <= 100)
		return (this->_ideas)[index];
	return 0;
}

void	Brain::setIdea(int index, std::string const &idea) {
	if (index >= 0 && index <= 100)
		this->_ideas[index] = idea;

}
