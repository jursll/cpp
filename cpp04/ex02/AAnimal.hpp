#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

// a class is abstract if it contains at least one abstract method;
// it cannot be instantiated, but its non-abstract subclasses can.

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal& operator=(AAnimal const &src);
		virtual ~AAnimal();

		virtual void makeSound() const = 0; // "= 0" makes it pure virtual
		std::string getType() const;
};

#endif

/*
A Pure Virtual function is:
- A virtual function with = 0 at the end of the declaration
- A function that has no implementation in the base class
- A function that forces derived classes to implement it
*/
