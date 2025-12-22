#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name)
{
	std::cout << "Constructor for HumanB called." << std::endl;
	this->_weapon = 0;
}

HumanB::~HumanB()
{
	std::cout << "Destructor for HumanB called." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack ..." << std::endl;
}
