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

int ScalarConverter::isFloat(std::string string) {
	int p_count = 0;
	int f_count = 0;
	char* end_ptr;
	std::strtod(string.c_str(), &end_ptr);
	if (*end_ptr != 'f')
		return 0;
	for (size_t i = 0; i < string.length(); ++i) {
		if (string[i] == 'f')
			f_count++;
		if (string[i] == '.')
			p_count++;
	}
	if (std::isnan(std::atof(string.c_str())) || std::isinf(std::atof(string.c_str())))
		return 1;
	return (f_count == 1 && p_count == 1);
}

void ScalarConverter::printInt(std::string string, std::string type) {
	int i = std::atoi(string.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	std::cout << "ORIGINAL TYPE: " << type << std::endl;
	checkChar(i, c);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printChar(std::string string, std::string type) {
	char c = string[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "ORIGINAL TYPE: " << type << std::endl;
	std::cout << "char: " << c << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::printDouble(std::string string, std::string type) {
	double d = std::atof(string.c_str());
	char c = static_cast<char>(d);
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	std::cout << "ORIGINAL TYPE: " << type << std::endl;
	checkChar(i, c);
	checkInt(i);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printFloat(std::string string, std::string type)
{
	float f = std::atof(string.c_str());
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);
	int i = static_cast<int>(f);
	std::cout << "ORIGINAL TYPE: " << type << std::endl;
	checkChar(i, c);
	checkInt(i);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::checkChar(int i, char c) {
	std::cout << "char: ";
	if (!std::isprint(c) && i < 128 && i >= 0)
		std::cout << "non displayable" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::checkInt(int i) {
	if (i >= INT_MAX || i <= INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}
