#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat& operator=(WrongCat const &src);
		virtual ~WrongCat();

		void makeSound() const;
};

#endif
