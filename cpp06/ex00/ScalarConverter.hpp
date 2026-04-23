#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &oth);
		ScalarConverter &operator=(ScalarConverter const &oth);

		static bool isInt(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isFloat(const std::string& literal);

	public:
		static void convert(const std::string &string);
};

#endif
