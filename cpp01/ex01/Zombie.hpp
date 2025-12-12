#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();

        void    announce();
        std::string getName();
        void setName(std::string new_name);
};

#endif
