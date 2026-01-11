#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &source);
	ScavTrap& operator=(ScavTrap const &src);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};

#endif
