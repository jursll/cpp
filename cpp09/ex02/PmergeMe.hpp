#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cstddef>
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

		static bool byValue(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b);

		static std::vector<size_t> jacobsthalOrder(size_t count);

		template <typename PairT>
		typename PairT::iterator findByTag(PairT& chain, size_t tag);

		template <typename PairT>
		void fordJohnsonSort(PairT& items);

		PmergeMe(void);
};

#endif
