#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	public :

		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe &operator=(PmergeMe const &src);

		template <typename T>
		void display(const T& container);

		void mergeInsertSortDeque(std::deque<int>& arr);
		void mergeInsertSortList(std::list<int>& arr);

	private :

		template<typename T>
		void merge(std::list<T>& left, std::list<T>& right, std::list<T>& result);

		template<typename T>
		void mergeInsertionSort(std::list<T>& arr);

		PmergeMe(void);
};

#endif
