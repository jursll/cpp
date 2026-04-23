#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F function) {
	size_t i = 0;
	while (i < length) {
		function(array[i]);
		i++;
	}
}

template <typename T>
void printElement(T& element) {
	std::cout << element << " ";
}

#endif
