#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator=(Dog const &src);
		virtual ~Dog();

		virtual void makeSound() const;
		void setType(std::string newType);
		Brain* getBrain() const;
};

#endif
