#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	/*
	const AAnimal* animal = new AAnimal();
	animal->makeSound();
	delete animal;
	*/
	std::cout << "___ Basic construction and destruction ___" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n___ Testing deep copy (copy constructor) ___" << std::endl;
	{
		Dog basic;
		basic.getBrain()->setIdea(0, "I love bones!");
		basic.getBrain()->setIdea(1, "Chase the cat!");

		std::cout << "\n- Creating copy via copy constructor:" << std::endl;
		Dog copy(basic);

		std::cout << "\nOriginal dog idea 0: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied dog idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n- Modifying copy's brain:" << std::endl;
		copy.getBrain()->setIdea(0, "I hate bones!");

		std::cout << "Original dog idea 0: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied dog idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n___ Testing deep copy (assignment operator) ___" << std::endl;
	{
		Cat cat1;
		cat1.getBrain()->setIdea(0, "Sleep for 20 hours zzz");
		cat1.getBrain()->setIdea(1, "Chase the mouse!");

		Cat cat2;
		cat2.getBrain()->setIdea(0, "Miaou loudly at 3am");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n- Assigning cat1 to cat2:" << std::endl;
		cat2 = cat1;

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n- Modifying cat2's brain:" << std::endl;
		cat2.getBrain()->setIdea(0, "Ignore the humans");

		std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n__ Testing array of Animals __" << std::endl;
	{
		const int size = 4;
		AAnimal* animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		std::cout << "\nAll animals making sounds:" << std::endl;
		for (int i = 0; i < size; i++)
			animals[i]->makeSound();

		std::cout << "\nDeleting all animals:" << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	return 0;
}
