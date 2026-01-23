#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(Cat const &src);
		Cat& operator=(Cat const &src);
		virtual ~Cat();

		virtual void makeSound() const;
		void setType(std::string newType);
		Brain* getBrain() const;
};

#endif
