#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "Constructor for HumanA called." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor for HumanA called." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
