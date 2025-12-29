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

		//Overloaded Comparison Operators:
		bool operator > (const Fixed &f) const;
		bool operator < (const Fixed &f) const;
		bool operator >= (const Fixed &f) const;
		bool operator <= (const Fixed &f) const;
		bool operator == (const Fixed &f) const;
		bool operator != (const Fixed &f) const;

		//Overload Arithmetic Operators:
/*float*/ Fixed operator + (const Fixed &f) const;
/*float*/ Fixed operator - (const Fixed &f) const;
/*float*/ Fixed operator * (const Fixed &f) const;
/*float*/ Fixed operator / (const Fixed &f) const;

		//The 4 increment/decrement:
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		//Overload member functions:
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(Fixed const &f1, const Fixed &f2);

		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(Fixed const &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &os, Fixed const &f);

#endif
