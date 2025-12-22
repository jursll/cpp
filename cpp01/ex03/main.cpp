#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\n\n" << std::endl;
	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "\n\n" << std::endl;
	{
		Weapon club("crude spiked club");
		HumanB tom("Tom");
		tom.attack();
		tom.setWeapon(club);
		tom.attack();
	}
	return 0;
}
