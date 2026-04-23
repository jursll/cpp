#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << "Null\n";
		return;
	}
	if (dynamic_cast<A*>(p)) std::cout << "A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "C\n";
	else std::cout << "Unknown\n";
}
// dynamic_cast on a pointer (A*) → if it fails, it returns nullptr
// dynamic_cast on a reference (A&) → if it fails, it throws an exception (std::bad_cast)
void identify(Base& p)
{
	//If you do not know the throw type used in the try block, you can use the "three dots" syntax (...) inside the catch block,
	//which will handle any type of exception:
	try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; }
	catch (...){ std::cout << "not A\n"; }
	try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; }
	catch (...){ std::cout << "not B\n"; }
	try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; }
	catch (...){ std::cout << "not C\n"; }

	std::cout << "Unknown\n";
}

int main()
{
	for (int k = 0; k < 10; ++k)
	{
		Base* ptr = generate();

		std::cout << "identify(ptr): ";
		identify(ptr);

		std::cout << "identify(*ptr): ";
		identify(*ptr);

		delete ptr;
		std::cout << "----\n";
	}
	return 0;
}
