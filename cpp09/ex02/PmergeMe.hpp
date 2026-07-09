#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	std::vector<int> sortVector(const std::vector<int> &input) const;
	std::deque<int>  sortDeque(const std::deque<int> &input) const;

private:
	std::vector<size_t> mergeInsertSortVector(const std::vector<int> &values, std::vector<size_t> idx) const;
	void binaryInsertVector(const std::vector<int> &values, std::vector<size_t> &chain, size_t idx, size_t bound) const;

	std::deque<size_t> mergeInsertSortDeque(const std::deque<int> &values, std::deque<size_t> idx) const;
	void binaryInsertDeque(const std::deque<int> &values, std::deque<size_t> &chain, size_t idx, size_t bound) const;

	std::vector<size_t> jacobsthalSequence(size_t upTo) const;
};

#endif
