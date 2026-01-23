#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const &src);
		Brain& operator=(Brain const &src);
		~Brain();

		std::string getIdea(int index) const;
		void	setIdea(int index, std::string const &idea);
};

#endif
