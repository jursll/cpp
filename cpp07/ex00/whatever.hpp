#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T max(const T& x, const T& y) {
	if (x > y)
		return x;
	else if (x < y)
		return y;
	else
		return y;
}

template <typename T>
T min(const T& x, const T& y) {
	if (x < y)
		return x;
	else if (y < x)
		return y;
	else
		return y;
}

#endif
