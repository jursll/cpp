#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
	private:
		T* _array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		Array& operator=(const Array& src);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;

	class IndexOutOfRangeException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Out of range");
			}
	};
};

#endif
