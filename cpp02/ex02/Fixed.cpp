#include "Fixed.hpp"

Fixed::Fixed() : _fixed_p(0)
{
	//std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int num)
{
	_fixed_p = num << _const_int;
	//std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float num)
{
	_fixed_p = (int)(num * (1 << _const_int));
	//std::cout << "Float constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called." << std::endl;
	//this->_fixed_p = f._fixed_p;
	//or Reuse assignment operator:
	*this = f;
}

Fixed & Fixed::operator=(const Fixed &f)
{
	//std::cout << "Copy assignment operator called." << std::endl;
	if (this != &f)
		this->_fixed_p = f.getRawBits(); // f._fixed_p;
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits() const
{
	//std::cout << "Member function getRawBits called." << std::endl;
	return this->_fixed_p;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_p = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_fixed_p) / (1 << _const_int));
}

int Fixed::toInt() const
{
	return (_fixed_p >> _const_int);
}

std::ostream &operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return os;
}

//Overloaded Comparison Operators:
bool	Fixed::operator > (const Fixed &f) const
{
	return (_fixed_p > f._fixed_p);
}

bool	Fixed::operator < (const Fixed &f) const
{
	return (_fixed_p < f._fixed_p);
}

bool	Fixed::operator >= (const Fixed &f) const
{
	return (_fixed_p >= f._fixed_p);
}

bool	Fixed::operator <= (const Fixed &f) const
{
	return (_fixed_p <= f._fixed_p);
}

bool	Fixed::operator == (const Fixed &f) const
{
	return (_fixed_p == f._fixed_p);
}

bool	Fixed::operator != (const Fixed &f) const
{
	return (_fixed_p != f._fixed_p);
}

//Overload Arithmetic Operators:
Fixed	Fixed::operator +(const Fixed &f) const
{
	return(this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator -(const Fixed &f) const
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator * (const Fixed &f) const
{
	return(this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator / (const Fixed &f) const
{
	return(this->toFloat() / f.toFloat());
}

//The 4 increment/decrement:
Fixed	Fixed::operator++()
{
	this->_fixed_p++;
	return(*this);
}

Fixed	Fixed::operator--()
{
	this->_fixed_p--;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tempor(*this);
	_fixed_p++;
	return (tempor);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tempor(*this);
	_fixed_p--;
	return (tempor);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if(f1 < f2)
		return(f1);
	return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if(f1 < f2)
		return(f1);
	return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if(f1 < f2)
		return(f2);
	return f1;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if(f1 < f2)
		return(f2);
	return f1;
}
