#include "PmergeMe.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <algorithm>
#include <utility>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parseArguments(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _input(other._input),
	  _vector(other._vector),
	  _deque(other._deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_input = other._input;
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortVector()
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	fordJohnsonVector(_vector);
	gettimeofday(&end, NULL);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "After: " << RESET;
	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void PmergeMe::sortDeque()
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	fordJohnsonDeque(_deque);
	gettimeofday(&end, NULL);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << std::endl;
}

void PmergeMe::printTimeVector() const
{
	std::cout << "Time to process a range of "
			  << _vector.size()
			  << " elements with std::vector : "
			  << _vectorTime
			  << " us";
}

void PmergeMe::printTimeDeque() const
{
	std::cout << "Time to process a range of "
			  << _deque.size()
			  << " elements with std::deque : "
			  << _dequeTime
			  << " us"
			  << std::endl;
}

void PmergeMe::parseArguments(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		char *end;
		errno = 0;
		long value = std::strtol(argv[i], &end, 10);

		if(end == argv[i] || *end != '\0' || errno == ERANGE || value <= 0 ||value > INT_MAX)
		{
			throw std::runtime_error("Error");
		}
		int number = static_cast<int>(value);
		for(std::size_t j = 0; j < _vector.size(); j++)
		{
			if(_vector[j] == number)
				throw std::runtime_error("Error");
		}
		_vector.push_back(number);
		_deque.push_back(number);
	}
}

void PmergeMe::printContainerVector() const
{
	std::cout << BOLD << RED << "Before: " << RESET;
	for(size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int> &numbers)
{
	if (numbers.size() <= 1)
		return;

	std::vector<std::pair<int, int> >pairs;
	for (size_t i = 0; i + 1 < numbers.size(); i+=2)
	{
		int first = numbers[i];
		int second = numbers[i+1];
		if (first > second)
			std::swap(first, second);
		int small = first;
		int big = second;
		pairs.push_back(std::make_pair(small, big));
	}

	bool hasStraggler = false;
	int straggler = 0;

	if (numbers.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = numbers.back();
	}
	std::vector<int> bigNumbers;
	for(size_t j = 0; j < pairs.size(); j++)
	{
		bigNumbers.push_back(pairs[j].second);
	 }
	fordJohnsonVector(bigNumbers);
	std::vector<int> mainChain;
	std::vector<std::pair<int, int> >orderedPairs;
	for(size_t i = 0; i < bigNumbers.size(); i++)
	{
		for(size_t j = 0; j < pairs.size(); j++)
		{

			if(pairs[j].second == bigNumbers[i])
			{
				orderedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	pairs = orderedPairs;
	mainChain.push_back(pairs[0].first);
	for(std::size_t i = 0; i < bigNumbers.size(); i++)
	{
		mainChain.push_back(bigNumbers[i]);
	}
	insertPendingVector(mainChain, orderedPairs);
	if (hasStraggler)
	{

		std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(),straggler);
		mainChain.insert(position, straggler);
	}
	numbers = mainChain;
}

void PmergeMe::insertPendingVector(std::vector<int> &mainChain, const std::vector<std::pair<int, int> > &orderedPairs)
{
	if (orderedPairs.size() <= 1)
		return;

	size_t previous = 1;
	size_t current = 3;

	while (previous < orderedPairs.size())
	{
		size_t groupStart = previous + 1;
		size_t groupEnd = current;

		if (groupEnd > orderedPairs.size())
			groupEnd = orderedPairs.size();

		for (size_t i = groupEnd; ; --i)
		{
			int pending = orderedPairs[i - 1].first;
			int partner = orderedPairs[i - 1].second;

			std::vector<int>::iterator partnerIt =
				std::find(mainChain.begin(), mainChain.end(), partner);

			if (partnerIt == mainChain.end())
			{
				std::cerr << "Error: partner not found" << std::endl;
				return;
			}
			std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), partnerIt, pending);
			mainChain.insert(position, pending);

			if (i == groupStart)
				break;
		}

		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &numbers)
{
	if (numbers.size() <= 1)
		return;

	std::deque<std::pair<int, int> >pairs;
	for (size_t i = 0; i + 1 < numbers.size(); i+=2)
	{
		int first = numbers[i];
		int second = numbers[i+1];
		if (first > second)
			std::swap(first, second);
		int small = first;
		int big = second;
		pairs.push_back(std::make_pair(small, big));
	}
	bool hasStraggler = false;
	int straggler = 0;

	if (numbers.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = numbers.back();
	}
	std::vector<int> bigNumbers;
	for(size_t j = 0; j < pairs.size(); j++)
	{
		bigNumbers.push_back(pairs[j].second);
	}
	fordJohnsonVector(bigNumbers);
	std::deque<int> mainChain;
	std::deque<std::pair<int, int> >orderedPairs;
	for(size_t i = 0; i < bigNumbers.size(); i++)
	{
		for(size_t j = 0; j < pairs.size(); j++)
		{

			if(pairs[j].second == bigNumbers[i])
			{
				orderedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	pairs = orderedPairs;
	mainChain.push_back(pairs[0].first);
	for(std::size_t i = 0; i < bigNumbers.size(); i++)
	{
		mainChain.push_back(bigNumbers[i]);
	}
	insertPendingDeque(mainChain, orderedPairs);
	if (hasStraggler)
	{
		std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(),straggler);
		mainChain.insert(position, straggler);
	}
	numbers = mainChain;
}

void PmergeMe::insertPendingDeque(std::deque<int> &mainChain, const std::deque<std::pair<int, int> > &orderedPairs)
{
	if (orderedPairs.size() <= 1)
		return;

	size_t previous = 1;
	size_t current = 3;

	while (previous < orderedPairs.size())
	{
		size_t groupStart = previous + 1;
		size_t groupEnd = current;

		if (groupEnd > orderedPairs.size())
			groupEnd = orderedPairs.size();

		for (size_t i = groupEnd; ; --i)
		{
			int pending = orderedPairs[i - 1].first;
			int partner = orderedPairs[i - 1].second;

			std::deque<int>::iterator partnerIt =
				std::find(mainChain.begin(), mainChain.end(), partner);

			if (partnerIt == mainChain.end())
			{
				std::cerr << "Error: partner not found" << std::endl;
				return;
			}
			std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), partnerIt, pending);
			mainChain.insert(position, pending);

			if (i == groupStart)
				break;
		}
		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}
}
