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

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (static_cast<unsigned int>(std::distance(begin, end)) > (this->_size - this->_container.size()))
				throw TooManyNumbersException();
			this->_container.insert(_container.end(), begin, end);
		}

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
