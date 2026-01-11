#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	First("Julia");
	ClapTrap	Second("Jetmir");
	ScavTrap	Third("Laure");
	FragTrap	Fourth("Bruno");

	First.playerStatus();
	Second.playerStatus();
	Third.playerStatus();
	Fourth.playerStatus();

	First.attack(Second.getName());
	Second.takeDamage(First.getDamage());
	std::cout << std::endl;
	First.attack(Second.getName());
	Second.takeDamage(First.getDamage());
	std::cout << std::endl;
	Second.attack(First.getName());
	First.takeDamage(Second.getDamage());
	std::cout << std::endl;
	First.beRepaired(5);
	std::cout << std::endl;
	Third.attack(First.getName());
	First.takeDamage(Third.getDamage());
	std::cout << std::endl;
	First.attack(Third.getName());
	std::cout << std::endl;
	Third.guardGate();
	std::cout << std::endl;
	Fourth.attack(Third.getName());
	Third.takeDamage(Fourth.getDamage());
	// First.guardGate();
	std::cout << std::endl;
	Fourth.highFivesGuys();
	//Third.highFivesGuys();

	First.playerStatus();
	Second.playerStatus();
	Third.playerStatus();
	Fourth.playerStatus();
}
