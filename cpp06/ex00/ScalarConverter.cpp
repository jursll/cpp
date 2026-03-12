#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src) {
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string string) {
	std::string type = getType(string);
	if (type == "char")
		printChar(string, type);
	else if (type == "int")
		printInt(string, type);
	else if (type == "double")
		printDouble(string, type);
	else if (type == "float")
		printFloat(string, type);
	else
		std::cerr << "Invalid type" << std::endl;
}

std::string ScalarConverter::getType(std::string string) {
	if (isChar(string))
		return "char";
	else if (isInt(string))
		return "int";
	else if (isDouble(string))
		return "double";
	else if (isFloat(string))
		return "float";
	else
		return "unknown";
}

int ScalarConverter::isChar(std::string string) {
	if (string.size() != 1 || std::isdigit(string[0]))
		return 0;
	else
		return 1;
}

int ScalarConverter::isInt(std::string string) {
	if (string.empty())
		return 0;

	char* end_ptr;
	errno = 0;
	long int converted = std::strtol(string.c_str(), &end_ptr, 0);

	if (errno == 0 && *end_ptr == '\0' && converted >= INT_MIN && converted <= INT_MAX)
		return 1;
	return 0;
}

int ScalarConverter::isDouble(std::string string) {
	char* end_ptr;
	int pointCount = 0;
	double result = std::strtod(string.c_str(), &end_ptr);
	if (*end_ptr != '\0' || end_ptr  == string.c_str() || (string[0] == '.' && string.size() == 1))
		return 0;
	for (size_t i = 0; i < string.length(); i++) {
		if (string[i] == '.')
			pointCount++;
	}
	if((pointCount > 1 || pointCount == 0) && (!(std::isnan(result) || std::isinf(result))))
		return 0;
	return 1;
}
