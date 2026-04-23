#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 4;

	std::cout << "a = " << a << "; b = " << b << std::endl;
	std::cout << "-- SWAPPING A & B --" << std::endl;
	::swap(a,b);
	std::cout << "a = " << a << "; b = " << b << std::endl;
	std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
	std::cout << "max(a,b) = " << ::max(a,b) << std::endl;

	std::cout << "\n\n" << std::endl;

	std::string c = "Hello ";
	std::string d = "World !";

	std::cout << "c = " << c << "; d = " << d << std::endl;
	std::cout << "-- SWAPPING C & D --" << std::endl;
	::swap(c,d);
	std::cout << "c = " << c << "; d = " << d << std::endl;
	std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
	std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
}
