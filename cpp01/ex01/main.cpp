#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	int i = 0;
	int num = 10;

	std::cout << "Creating " << num << " zombies..." << std::endl;
	Zombie *group;
	group = zombieHorde(num, "Julia");

	std::cout << "\n\n" << std::endl;

	Zombie *current = group;
	std::cout << "Big zombies annouce !" << std::endl;
	while (i < num)
	{
		std::cout << i + 1 << " ";
		current->announce();
		i++;
		current++;
	}
	i = 0;

	std::cout << "\n\n" << std::endl;

	std::cout << "Deleting all the zombies" << std::endl;
	delete [] group;
}
