#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int 		_attackDamage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap const &src);	// copy constructor
		ClapTrap& operator=(ClapTrap const &src);	// assignment operator

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	playerStatus();

		std::string	getName();
		int	getDamage();
};

#endif
