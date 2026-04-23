#include "Array.tpp"

#define MAX_VAL 750

int main(int, char**) {
	{
		unsigned int s = 5;
		std::cout << "\033[34m--Create array of int with no value inside--\033[0m" << std::endl;
		Array<int> array(s);
		std::cout << "array.size = " << array.size() << std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "\033[34m--Array of int, size 4 with 3 values only--\033[0m" << std::endl;
		Array<int> array(4);
		std::cout << "array.size = " << array.size() << std::endl;
		array[0] = 1234;
		array[1] = 42;
		array[2] = 8;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "\033[34m--Empty array--\033[0m" << std::endl;
		Array<int> array;
		std::cout << "array.size = " << array.size() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "\033[34m--Assignment operator--\033[0m" << std::endl;
		Array<int> array(3);
		array[0] = 1234;
		array[1] = 42;
		array[2] = 8;

		Array<int> array2;
		array2 = array;
		array2[0] = 0;
		array2[1] = 9876;
		array[0] = 2;
		for (unsigned int i = 0; i < array2.size(); i++)
			std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
		std::cout << std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "\033[34m--Copy constructor--\033[0m" << std::endl;
		Array<int> array(3);
		array[0] = 1234;
		array[1] = 42;
		array[2] = 8;

		Array<int> array2(array);
		array2[0] = 0;
		array2[1] = 9876;
		array[0] = 2;
		for (unsigned int i = 0; i < array2.size(); i++)
			std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
		std::cout << std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "\033[34m--Out of bounds exception--\033[0m" << std::endl;
		Array<int> array(3);
		try {
			std::cout << array[3] << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
