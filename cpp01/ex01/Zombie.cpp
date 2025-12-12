#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Constructor for Zombie called." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor for Zombie called." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string new_name)
{
    this->_name = new_name;
}

std::string Zombie::getName()
{
    return (this->_name);
}
