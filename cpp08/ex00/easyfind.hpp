#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Not found");
		}
};

template<typename T>
void easyfind(T& container, int to_find) {
	typename T::iterator result; //Iterators are used to point at the memory addresses of STL containers

	result = std::find(container.begin(), container.end(), to_find);
	if (result == container.end())
		throw (NotFoundException());
	else {
		int index = std::distance(container.begin(), result);
		std::cout << "Value found at index: " << index << std::endl;
	}
}

#endif
