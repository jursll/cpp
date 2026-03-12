#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <cstring>
# include <limits.h>
# include <cfloat>
# include <cmath>
# include <ostream>
# include <stdlib.h>

class ScalarConverter {
	public:
		static void convert(std::string string);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter& operator=(ScalarConverter const &src);
		~ScalarConverter();

		static std::string getType(std::string string);

		static int isInt(std::string string);
		static int isFloat(std::string string);
		static int isChar(std::string string);
		static int isDouble(std::string string);

		static void printInt(std::string string, std::string type);
		static void printFloat(std::string string, std::string type);
		static void printChar(std::string string, std::string type);
		static void printDouble(std::string string, std::string type);

		static void checkChar(int i, char c);
		static void checkInt(int i);
};

#endif
