#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		unsigned int		_size;
		std::vector<int>	_container;

	class TooManyNumbersException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Container is too small");
			}
	};

	class TooFewNumbersException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Not enough numbers to find a span");
			}
	};
};

#endif
