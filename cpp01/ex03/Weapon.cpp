#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type)
{
	std::cout << "Constructor for Weapon called." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destructor for Weapon called." << std::endl;
}

std::string const &Weapon::getType() const
{
	return(this->_type);
}

void Weapon::setType(const std::string &newType)
{
	this->_type = newType;
}
