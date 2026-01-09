#include "ClapTrap.hpp"

int main()
{
	ClapTrap	playerOne("Julia");
	ClapTrap	playerTwo("Jetmir");

	playerOne.playerStatus();
	playerTwo.playerStatus();

	playerOne.attack(playerTwo.getName());
	playerTwo.takeDamage(playerOne.getDamage());
	std::cout << std::endl;
	playerOne.attack(playerTwo.getName());
	playerTwo.takeDamage(playerOne.getDamage());
	std::cout << std::endl;
	playerTwo.attack(playerOne.getName());
	std::cout << std::endl;
	playerOne.beRepaired(5);
	playerTwo.beRepaired(5);

	playerOne.playerStatus();
	playerTwo.playerStatus();

	return 0;
}
