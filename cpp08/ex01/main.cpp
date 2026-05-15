#include "Span.hpp"

int main() {
	{
		std::cout << "\033[34mExample given in the subject:\033[0m" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		std::cout << "\033[31mAdding too many numbers:\033[0m" << std::endl;
		try {
			Span sp = Span(1);
			sp.addNumber(1);
			sp.addNumber(2);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		std::cout << "\033[31mInvalid shortest span:\033[0m" << std::endl;
		try {
			Span sp = Span(1);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		std::cout << "\033[31mInvalid longest span:\033[0m" << std::endl;
		try {
			Span sp = Span(1);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		std::cout << "\033[32mTry with >10000 numbers:\033[0m" << std::endl;
		try {
			Span sp = Span(15000);
			for (int i = 0; i < 15000; i++)
				sp.addNumber(i);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n-----------------\n" << std::endl;
{
	std::cout << "\033[32mUsing addRange template:\033[0m" << std::endl;
	try
	{
		std::cout << "--- From a vector: " << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i);

		Span sp = Span(5);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try
	{
		std::cout << "--- From a classic array: " << std::endl;
		int arr[] = {10, 3, 7, 1, 9};

		Span sp = Span(5);
		sp.addRange(arr, arr + 5);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try
	{
		std::cout << "--- Too many elements: " << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		Span sp = Span(5);
		sp.addRange(vec.begin(), vec.end());
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
}
}
