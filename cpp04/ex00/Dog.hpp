#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator=(Dog const &src);
		virtual ~Dog();

		virtual void makeSound() const;
};

#endif
