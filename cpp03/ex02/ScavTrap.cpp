#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor for ScavTrap " << this->_name << " called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap " << this->_name << " called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &source) : ClapTrap(source)
{
	std::cout << "Copy construcor for ScavTrap called." << std::endl;
	*this = source;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Assignment operator for ScavTrap called." << std::endl;

	ClapTrap::operator=(src);

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more energy, he can't attack..." << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " is dead! x.x" << std::endl;
	}
	else if (this->_attackDamage == 0)
	{
		std::cout << "ScavTrap " << this->_name << " didn't cause any damage" << std::endl;
		this->_energyPoints -= 1;
		std::cout << "Remaining energy for ScavTrap " << this->_name << ": " << this->_energyPoints << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacked " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
		std::cout << "Remaining energy for ScavTrap " << this->_name << ": " << this->_energyPoints << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is guarding the gate!" << std::endl;
}
