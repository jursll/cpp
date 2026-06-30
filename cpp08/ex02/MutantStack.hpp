#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack<T> &operator=(const MutantStack &src);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif
