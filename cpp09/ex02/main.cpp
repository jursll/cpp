#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cerrno>
#include <stdexcept>
#include <string>

static bool parsePositiveInt(const std::string &s, int &out)
{
	if (s.empty())
		return false;

	size_t i = 0;
	if (s[0] == '+')
		i = 1;
	if (i == s.size())
		return false;

	for (size_t j = i; j < s.size(); ++j)
		if (!std::isdigit(static_cast<unsigned char>(s[j])))
			return false;

	errno = 0;
	char *end = NULL;
	long value = std::strtol(s.c_str(), &end, 10);

	if (errno == ERANGE || value <= 0 || value > INT_MAX)
		return false;
	out = static_cast<int>(value);
	return true;
}

static std::vector<int> parseArgs(int argc, char **argv)
{
	std::vector<int> values;

	for (int i = 1; i < argc; ++i)
	{
		int value;
		if (!parsePositiveInt(argv[i], value))
			throw std::runtime_error("Error");
		values.push_back(value);
	}
	return values;
}

static void printContainer(const std::string &label, const std::vector<int> &c)
{
	std::cout << label;
	for (std::vector<int>::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static double nowMicroseconds()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return static_cast<double>(ts.tv_sec) * 1000000.0 + static_cast<double>(ts.tv_nsec) / 1000.0;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		std::vector<int> input = parseArgs(argc, argv);
		std::deque<int> inputDeque(input.begin(), input.end());

		PmergeMe pmerge;

		printContainer("Before:", input);

		double startVec = nowMicroseconds();
		std::vector<int> sortedVec = pmerge.sortVector(input);
		double endVec = nowMicroseconds();

		double startDeq = nowMicroseconds();
		std::deque<int> sortedDeq = pmerge.sortDeque(inputDeque);
		double endDeq = nowMicroseconds();

		printContainer("After:", sortedVec);

		std::cout << "Time to process a range of " << input.size()
			<< " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;
		std::cout << "Time to process a range of " << input.size()
			<< " elements with std::deque  : " << (endDeq - startDeq) << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
