#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Constructor for MutantStack called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) {
	std::cout << "Copy constructor for MutantStack called" << std::endl;
	*this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
	std::cout << "Assignment operator for MutantStack called" << std::endl;
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Destructor for MutantStack called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

#endif
