#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
		ClapTrap	First("Julia");
		ClapTrap	Second("Jetmir");
		ScavTrap	Third("Laure");

		First.playerStatus();
		Second.playerStatus();
		Third.playerStatus();

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
		// First.guardGate();   //test to see that it doesn't work
		std::cout << std::endl;

		First.playerStatus();
		Second.playerStatus();
		Third.playerStatus();
}
