#include "PmergeMe.hpp"


/* ---- CONSTRUCTORS & DESTRUCTORS ------ */


PmergeMe::PmergeMe(void) {
	std::cout << "\033[90mConstructor for PmergeMe\033[0m" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "\033[90mConstructor for PmergeMe\033[0m" << std::endl;

	std::deque<int> inputDeque;
	std::list<int> inputList;

	for (int i = 1; i < argc; ++i)
	{
		int value = atoi(argv[i]);
		if (value <= 0)
		{
			std::cerr << "\033[1;31mError: Only positive integers are allowed.\033[0m" << std::endl;
			exit(1);
		}
		inputDeque.push_back(value);
		inputList.push_back(value);
	}
	std::cout << "Before: ";
	display(inputDeque);

	clock_t start1 = clock();
	mergeInsertSortDeque(inputDeque);
	clock_t end1 = clock();
	double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;

	clock_t start2 = clock();
	mergeInsertSortList(inputList);
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	display(inputDeque);
	std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
	if (inputDeque == std::deque<int>(inputList.begin(), inputList.end()))
		std::cout << "The sorted sequences are equal." << std::endl;
	else
		std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	(void) src;
	std::cout << "\033[90mCopy constructor for PmergeMe\033[0m" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
	(void) src;
	std::cout << "\033[90mAssignment operator for PmergeMe\033[0m" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe(void) {
	std::cout << "\033[90mDestructor for PmergeMe\033[0m" << std::endl;
	return ;
}


/* ------------ TEMPLATE ---------------- */


template <typename T>
void PmergeMe::display(const T& container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename PairT>
typename PairT::iterator PmergeMe::findByTag(PairT& chain, size_t tag)
{
	typename PairT::iterator it = chain.begin();
	while (it != chain.end() && it->second != tag)
		++it;
	return it;
}

template <typename PairT>
void PmergeMe::fordJohnsonSort(PairT& items)
{
	if (items.size() <= 1)
		return;

	PairT winners;
	std::vector<std::pair<int, size_t> > companions;
	std::vector<size_t> partnerTag;
	bool hasStraggler = false;
	std::pair<int, size_t> straggler(0, 0);

	typename PairT::iterator it = items.begin();
	while (it != items.end())
	{
		std::pair<int, size_t> x = *it++;
		if (it == items.end())
		{
			straggler = x;
			hasStraggler = true;
			break;
		}
		std::pair<int, size_t> y = *it++;
		if (x.first < y.first)
		{
			winners.push_back(y);
			companions.push_back(x);
		}
		else
		{
			winners.push_back(x);
			companions.push_back(y);
		}
		partnerTag.push_back(winners.back().second);
	}

	fordJohnsonSort(winners);

	PairT& chain = winners;

	for (size_t i = 0; i < companions.size(); ++i)
	{
		typename PairT::iterator bound = findByTag(chain, partnerTag[i]);
		typename PairT::iterator pos = std::lower_bound(chain.begin(), bound, companions[i], byValue);
		chain.insert(pos, companions[i]);
	}

	if (hasStraggler)
	{
		typename PairT::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler, byValue);
		chain.insert(pos, straggler);
	}

	items.swap(chain);
}


/* ------------ FUNCTIONS --------------- */


bool PmergeMe::byValue(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b)
{
	return a.first < b.first;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
	std::deque<std::pair<int, size_t> > tagged;
	size_t tag = 0;
	for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); ++it)
		tagged.push_back(std::make_pair(*it, tag++));

	fordJohnsonSort(tagged);

	arr.clear();
	for (std::deque<std::pair<int, size_t> >::iterator it = tagged.begin(); it != tagged.end(); ++it)
		arr.push_back(it->first);
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
	std::list<std::pair<int, size_t> > tagged;
	size_t tag = 0;
	for (std::list<int>::iterator it = arr.begin(); it != arr.end(); ++it)
		tagged.push_back(std::make_pair(*it, tag++));

	fordJohnsonSort(tagged);

	arr.clear();
	for (std::list<std::pair<int, size_t> >::iterator it = tagged.begin(); it != tagged.end(); ++it)
		arr.push_back(it->first);
}
