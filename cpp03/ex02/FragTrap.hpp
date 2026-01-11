#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &source);
	FragTrap& operator=(FragTrap const &src);
	~FragTrap();

	void highFivesGuys();
};

#endif
