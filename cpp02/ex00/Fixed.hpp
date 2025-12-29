#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixed_p;
		static const int _const_int = 8;

	public:
		Fixed(); //Default Constructor
		Fixed(const Fixed &f); //Copy Constructor
		Fixed& operator=(const Fixed &f); //Copy assignment operator
		~Fixed(); //Destructor

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
