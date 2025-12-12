#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Constructor for " << this->_name << " Zombie called." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor for " << this->_name << " Zombie called." << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
