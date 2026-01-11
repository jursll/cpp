#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor for FragTrap " << this->_name << " called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor for FragTrap " << this->_name << " called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &source) : ClapTrap(source)
{
	std::cout << "Copy construcor for FragTrap called." << std::endl;
	*this = source;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Assignment operator for FragTrap called." << std::endl;

	ClapTrap::operator=(src);

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " gave a high fives!" << std::endl;
}
