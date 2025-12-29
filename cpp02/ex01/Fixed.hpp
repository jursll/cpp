#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixed_p;
		static const int _const_int = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &f); //Copy Constructor
		Fixed& operator=(const Fixed &f); //Copy assignment operator
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &f);

#endif
