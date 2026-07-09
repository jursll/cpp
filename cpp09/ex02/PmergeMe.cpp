#include "PmergeMe.hpp"
#include <algorithm>
#include <map>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t upTo) const
{
	std::vector<size_t> jac;

	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() < upTo)
		jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
	return jac;
}

/* ------------------------------------------------------------------ */
/*  std::vector implementation                                        */
/* ------------------------------------------------------------------ */

void PmergeMe::binaryInsertVector(const std::vector<int> &values, std::vector<size_t> &chain, size_t idx, size_t bound) const
{
	std::vector<size_t>::iterator lo = chain.begin();
	std::vector<size_t>::iterator hi = chain.begin() + bound;

	while (lo < hi)
	{
		std::vector<size_t>::iterator mid = lo + (hi - lo) / 2;
		if (values[*mid] < values[idx])
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(lo, idx);
}

std::vector<size_t> PmergeMe::mergeInsertSortVector(const std::vector<int> &values, std::vector<size_t> idx) const
{
	size_t n = idx.size();

	if (n <= 1)
		return idx;

	bool hasStraggler = (n % 2 == 1);
	size_t straggler = 0;
	if (hasStraggler)
	{
		straggler = idx.back();
		idx.pop_back();
		--n;
	}

	std::vector<size_t> smallerIdx(n / 2);
	std::vector<size_t> largerIdx(n / 2);
	for (size_t i = 0; i < n / 2; ++i)
	{
		size_t a = idx[2 * i];
		size_t b = idx[2 * i + 1];
		if (values[a] < values[b])
		{
			smallerIdx[i] = a;
			largerIdx[i] = b;
		}
		else
		{
			smallerIdx[i] = b;
			largerIdx[i] = a;
		}
	}

	std::vector<size_t> sortedLarger = mergeInsertSortVector(values, largerIdx);

	std::map<size_t, size_t> partner;
	for (size_t i = 0; i < largerIdx.size(); ++i)
		partner[largerIdx[i]] = smallerIdx[i];

	std::vector<size_t> chain = sortedLarger;
	chain.insert(chain.begin(), partner[sortedLarger[0]]);

	size_t m = sortedLarger.size();
	size_t placed = 1;
	std::vector<size_t> jac = jacobsthalSequence(m);

	for (size_t t = 3; placed < m; ++t)
	{
		if (t >= jac.size())
			break;
		size_t lo = jac[t - 1];
		if (lo >= m)
			break;
		size_t hi = jac[t];
		if (hi > m)
			hi = m;
		for (size_t rank = hi; rank > lo; --rank)
		{
			size_t largeIdx = sortedLarger[rank - 1];
			size_t pendIdx = partner[largeIdx];
			std::vector<size_t>::iterator boundIt = std::find(chain.begin(), chain.end(), largeIdx);
			binaryInsertVector(values, chain, pendIdx, static_cast<size_t>(boundIt - chain.begin()));
			++placed;
		}
	}

	if (hasStraggler)
		binaryInsertVector(values, chain, straggler, chain.size());

	return chain;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) const
{
	std::vector<size_t> idx(input.size());
	for (size_t i = 0; i < input.size(); ++i)
		idx[i] = i;

	std::vector<size_t> sortedIdx = mergeInsertSortVector(input, idx);

	std::vector<int> result(input.size());
	for (size_t i = 0; i < sortedIdx.size(); ++i)
		result[i] = input[sortedIdx[i]];
	return result;
}

/* ------------------------------------------------------------------ */
/*  std::deque implementation                                         */
/* ------------------------------------------------------------------ */

void PmergeMe::binaryInsertDeque(const std::deque<int> &values, std::deque<size_t> &chain, size_t idx, size_t bound) const
{
	std::deque<size_t>::iterator lo = chain.begin();
	std::deque<size_t>::iterator hi = chain.begin() + bound;

	while (lo < hi)
	{
		std::deque<size_t>::iterator mid = lo + (hi - lo) / 2;
		if (values[*mid] < values[idx])
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(lo, idx);
}

std::deque<size_t> PmergeMe::mergeInsertSortDeque(const std::deque<int> &values, std::deque<size_t> idx) const
{
	size_t n = idx.size();

	if (n <= 1)
		return idx;

	bool hasStraggler = (n % 2 == 1);
	size_t straggler = 0;
	if (hasStraggler)
	{
		straggler = idx.back();
		idx.pop_back();
		--n;
	}

	std::deque<size_t> smallerIdx(n / 2);
	std::deque<size_t> largerIdx(n / 2);
	for (size_t i = 0; i < n / 2; ++i)
	{
		size_t a = idx[2 * i];
		size_t b = idx[2 * i + 1];
		if (values[a] < values[b])
		{
			smallerIdx[i] = a;
			largerIdx[i] = b;
		}
		else
		{
			smallerIdx[i] = b;
			largerIdx[i] = a;
		}
	}

	std::deque<size_t> sortedLarger = mergeInsertSortDeque(values, largerIdx);

	std::map<size_t, size_t> partner;
	for (size_t i = 0; i < largerIdx.size(); ++i)
		partner[largerIdx[i]] = smallerIdx[i];

	std::deque<size_t> chain = sortedLarger;
	chain.insert(chain.begin(), partner[sortedLarger[0]]);

	size_t m = sortedLarger.size();
	size_t placed = 1;
	std::vector<size_t> jac = jacobsthalSequence(m);

	for (size_t t = 3; placed < m; ++t)
	{
		if (t >= jac.size())
			break;
		size_t lo = jac[t - 1];
		if (lo >= m)
			break;
		size_t hi = jac[t];
		if (hi > m)
			hi = m;
		for (size_t rank = hi; rank > lo; --rank)
		{
			size_t largeIdx = sortedLarger[rank - 1];
			size_t pendIdx = partner[largeIdx];
			std::deque<size_t>::iterator boundIt = std::find(chain.begin(), chain.end(), largeIdx);
			binaryInsertDeque(values, chain, pendIdx, static_cast<size_t>(boundIt - chain.begin()));
			++placed;
		}
	}

	if (hasStraggler)
		binaryInsertDeque(values, chain, straggler, chain.size());

	return chain;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) const
{
	std::deque<size_t> idx(input.size());
	for (size_t i = 0; i < input.size(); ++i)
		idx[i] = i;

	std::deque<size_t> sortedIdx = mergeInsertSortDeque(input, idx);

	std::deque<int> result(input.size());
	for (size_t i = 0; i < sortedIdx.size(); ++i)
		result[i] = input[sortedIdx[i]];
	return result;
}
