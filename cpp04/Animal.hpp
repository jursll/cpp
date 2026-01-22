#ifndef ANIMAP_HPP
#define ANIMAP_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
