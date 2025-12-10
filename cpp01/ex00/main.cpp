#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    std::cout << "Creating a Zombie on the stack" << std::endl;
    {
        Zombie stackZombie = Zombie("Stacky");
        stackZombie.announce();
    }
    std::cout << "\n\n" << std::endl;

    std::cout << "Creating a Zombie on the heap" << std::endl;
    {
        Zombie *heapZombie = newZombie("Heappy");
        heapZombie->announce();
        delete heapZombie;
    }
    std::cout << "\n\n" << std::endl;

    std::cout << "Creating a Zombie with randomChump" << std::endl;
    {
        randomChump("Randommy");
    }
    
    return 0;
}