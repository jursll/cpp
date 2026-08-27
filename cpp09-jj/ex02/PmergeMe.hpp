#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstddef>
#include <sys/time.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

class PmergeMe
{
	private:
		std::vector<int>	_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_vectorTime;
		double 				_dequeTime;

		void	parseArguments(int argc, char **argv);

		void	fordJohnsonVector(std::vector<int> &numbers);
		void	insertPendingVector(std::vector<int> &mainChain, const std::vector<std::pair<int, int> > &orderedPairs);
//------------------------------------------------------------------------------------------------------------------------------
		void	fordJohnsonDeque(std::deque<int> &numbers);
		void	insertPendingDeque(std::deque<int> &mainChain, const std::deque<std::pair<int, int> > &orderedPairs);

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void	printTimeVector() const;
		void	printContainerVector() const;
		void	sortVector();
//-------------------------------------------------------------------------------------------------------------------------------
		void	sortDeque();
		void	printTimeDeque() const;
};

#endif
