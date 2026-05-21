#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {
	std::cout << "Constructor for Span called" << std::endl;
	this->_container.reserve(this->_size);
}

Span::Span(const Span &src) {
	std::cout << "Copy constructor for Span called" << std::endl;
	*this = src;
}

Span& Span::operator=(const Span &src) {
	std::cout << "Assignment operator for Span called" << std::endl;
	this->_container.reserve(this->_size);
	this->_container = src._container;
	return *this;
}

Span::~Span() {
	std::cout << "Destructor for Span called" << std::endl;
}

void Span::addNumber(int number) {
	if (this->_container.size() == this->_size)
		throw TooManyNumbersException();
	this->_container.push_back(number);
}

int Span::shortestSpan() {
	if (this->_container.size() <= 1)
		throw TooFewNumbersException();

	std::sort(this->_container.begin(), this->_container.end());
	int smallest = this->_container[1] - this->_container[0];
	for (unsigned int i = 2; i < this->_size; i++) {
		int current = this->_container[i] - this->_container[i - 1];
		if (current < smallest)
			smallest = current;
	}
	return smallest;
}

int Span::longestSpan() {
	if (this->_container.size() <= 1)
		throw TooFewNumbersException();

	int max = *max_element(this->_container.begin(), this->_container.end());
	int min = *min_element(this->_container.begin(), this->_container.end());
	return (max - min);
}

// a cast is needed because distance is a size_t type
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (static_cast<unsigned int>(std::distance(begin, end)) > (this->_size - this->_container.size()))
		throw TooFewNumbersException();
	this->_container.insert(_container.end(), begin, end);
}
