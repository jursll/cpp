#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		Cat& operator=(Cat const &src);
		virtual ~Cat();

		virtual void makeSound() const;
};

#endif
