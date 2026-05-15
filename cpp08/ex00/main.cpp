#include "easyfind.hpp"

int main() {
	std::vector<int> cont;
	//std::list<int> cont;
	//std::deque<int> cont;

	cont.push_back(1);
	cont.push_back(2);
	cont.push_back(3);
	cont.push_back(4);
	cont.push_back(42);

	int OK_to_find = 42;
	int KO_to_find = 123;

	std::cout << "Searching for " << OK_to_find << " and " << KO_to_find << "\n" << std::endl;
	try {
		std::cout << "\033[32mCorrect search:\033[0m" << std::endl;
		easyfind(cont, OK_to_find);
		std::cout << std::endl;
		std::cout << "\033[31mWrong search:\033[0m" << std::endl;
		easyfind(cont, KO_to_find);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
