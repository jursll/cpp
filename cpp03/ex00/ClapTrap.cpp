#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor for ClapTrap " << this->_name << " called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for ClapTrap " << this->_name << " called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor ClapTrap called." << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Assignment operator ClapTrap called." << std::endl;

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this-> _attackDamage = src._attackDamage;
	return (*this);
}

std::string ClapTrap::getName()
{
	return (this->_name);
}

int	ClapTrap::getDamage()
{
	return (this->_attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy, he can't attack..." << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " is dead! x.x" << std::endl;
	}
	else if (this->_attackDamage == 0)
	{
		std::cout << "ClapTrap " << this->_name << " did't cause any damage" << std::endl;
		this->_energyPoints -= 1;
		std::cout << "Remaining energy for ClapTrap " << this->_name << ": " << this->_energyPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacked " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
		std::cout << "Remaining energy for ClapTrap " << this->_name << ": " << this->_energyPoints << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0 && amount > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage" << std::endl;
		this->_hitPoints -= amount;
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << " died x.x" << std::endl;
		else
			std::cout << "Remaining HP for ClapTrap " << this->_name << ": " << this->_hitPoints << std::endl;
	}
	else if (this->_hitPoints <= 0)
		std::cout << "You can't attack a dead player x.x" << std::endl;
	else if (amount <= 0)
		std::cout << "Player who attacked " << this->_name << " did't cause any damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead x.x, can't repair anymore..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy, can't repair himself..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " regained " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		std::cout << "Remaining HP for ClapTrap " << this->_name << ": " << this->_hitPoints << std::endl;
	}
}

void	ClapTrap::playerStatus()
{
	std::cout << "\n***   Player Status   ***" << std::endl;
	std::cout << "*     Player: " << this->_name << std::endl;
	std::cout << "*     HP: " << this->_hitPoints << std::endl;
	std::cout << "*     Energy: " << this->_energyPoints << std::endl;
	std::cout << "*     Damage: " << this->_attackDamage << std::endl;
	std::cout << "*************************\n" << std::endl;
}
