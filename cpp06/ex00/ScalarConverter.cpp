#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called \n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &oth)
{
	(void)oth;
	std::cout << "Copy Constructor called for ScalarConverter \n";
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &oth)
{
	(void)oth;
	std::cout << "Assignet Constructor called for ScalarConverter \n";
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called for \n";
}

void ScalarConverter::convert(const std::string &literal)
{
	if(literal == "nan" || literal == "nanf")
	{
		if(literal == "nan")
			std::cout << "\033[33mtype is:Double\n\033[0m";
		if(literal == "nanf")
			std::cout << "\033[33mtype is: Float\n\033[0m";
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}

	else if(literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		if(literal == "+inf" || literal == "inf")
			std::cout << "\033[33mtype is: Double\n\033[0m";
		if(literal == "+inff" || literal == "inff")
			std::cout << "\033[33mtype is: Float\n\033[0m";
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
		return;
	}
	else if(literal == "-inf" || literal == "-inff")
	{
		if(literal == "-inf")
			std::cout << "\033[33mtype is: Double\n\033[0m";
		if(literal == "-inff")
			std::cout << "\033[33mtype is: Float\n\033[0m";
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return;
	}
	else if(literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "\033[33mtype is: Char\n\033[0m";
		std::cout << "char: '" << c << "'\n";
		std::cout << "int : " <<static_cast<int>(c)<<"\n";
		std::cout << "float : " <<static_cast<float>(c)<<".0f\n";
		std::cout << "double : " <<static_cast<double>(c)<<".0\n";
		return;
	}
	else if(isInt(literal))
	{
		errno = 0;
		char *end;
		long value = strtol(literal.c_str(), &end, 10);
		if(value < INT_MIN || value > INT_MAX || *end != '\0' || errno == ERANGE)
		{
			std::cout << "\033[33mtype is out of range of Int but still can ba converted to float and double\n\033[0m";
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : " << static_cast<float>(value) <<"0f\n";
			std::cout << "double : " << static_cast<double>(value)<<"0\n";
			return;
		}
		int intValue = value;
		std::cout << "\033[33mtype is: Integere\n\033[0m";
		if(intValue < 0 || intValue > 127)
		{
			std::cout << "char: impossible\n";
			std::cout << "int : "	 << static_cast<int>(intValue)<<"\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : "	 << static_cast<float>(intValue) <<"0f\n";
			std::cout << "double : " << static_cast<double>(intValue)<<"0\n";
		}
		else if(!std::isprint(intValue))
		{
			std::cout << "char: Non displayable\n";
			std::cout << "int : "	 << static_cast<int>(intValue)<<"\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : "	 << static_cast<float>(intValue) <<"0f\n";
			std::cout << "double : " << static_cast<double>(intValue)<<"0\n";
		}
		else
		{
		std::cout << "char: '"	 << static_cast<char>(intValue) << "'\n";
		std::cout << "int : "	 << static_cast<int>(intValue)<<"\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float : "	 << static_cast<float>(intValue) <<"0f\n";
		std::cout << "double : " << static_cast<double>(intValue)<<"0\n";
		return;
		}
	}
	else if(isDouble(literal))
	{
		errno = 0;
		char *end;
		double value = strtod(literal.c_str(), &end);
		if(*end != '\0' || errno == ERANGE)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float : impossible\n";
			std::cout << "double : impossible\n";
			return;
		}
		std::cout << "\033[33mtype is: Double\n\033[0m";
		double intPart = std::floor(value);
		if (value == intPart) // <-- zëvendëson kontrollin ".0"
		{
	if(value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		{
			std::cout << "char: impossible\n";
			std::cout << "int : impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : "  << static_cast<float>(value)  << "0f\n";
			std::cout << "double : " << value << "0\n";
			return;
		}

		int intValue = static_cast<int>(value);

		if(intValue < 0 || intValue > 127)
		{
			std::cout << "char: impossible\n";
			std::cout << "int : "   << intValue << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : " << static_cast<float>(value) << "0f\n";
			std::cout << "double : " << value << "0\n";
			return;
		}

		if(!std::isprint(static_cast<unsigned char>(intValue))) // <-- second fix
		{
			std::cout << "char: Non displayable\n";
			std::cout << "int : "   << intValue << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : " << static_cast<float>(value) << "0f\n";
			std::cout << "double : " << value << "0\n";
			return;
		}
		// here you can print a normal char if you want (you didn’t have it at all in this branch)
		std::cout << "char: '" << static_cast<char>(intValue) << "'\n";
		std::cout << "int : "   << intValue << "\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float : " << static_cast<float>(value) << "0f\n";
		std::cout << "double : " << value << "0\n";
		return;
		}
	}
	else if(isFloat(literal))
	{
		errno = 0;
		char *end;
		float value = strtof(literal.c_str(), &end);
		if(*end != 'f' || errno == ERANGE)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float : impossible\n";
			std::cout << "double : impossible\n";
			return;
		}
		std::cout << "\033[33mtype is: Float\n\033[0m";
		float intPart = std::floor(value);
		if (value == intPart) // <-- replaces the ".0" check
		{
	if(value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		{
			std::cout << "char: impossible\n";
			std::cout << "int : impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : "  << value << "0f\n";
			std::cout << "double : " << static_cast<double>(value)  << "0\n";
			return;
		}

		int intValue = static_cast<int>(value);
		if(intValue < 0 || intValue > 127)
		{
			std::cout << "char: impossible\n";
			std::cout << "int : "   << intValue << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : " << value << "0f\n";
			std::cout << "double : " << static_cast<double>(value) << "0\n";
			return;
		}

		if(!std::isprint(static_cast<unsigned char>(intValue))) // <-- second fix
		{
			std::cout << "char: Non displayable\n";
			std::cout << "int : "   << intValue << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : " << value << "0f\n";
			std::cout << "double : " << static_cast<double>(value) << "0\n";
			return;
		}
		// here you can print a normal char if you want (you didn’t have it at all in this branch)
		std::cout << "char: '" << static_cast<char>(intValue) << "'\n";
		std::cout << "int : "   << intValue << "\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float : " << value << "0f\n";
		std::cout << "double : " << static_cast<double>(value)<< "0\n";
		return;
		}
		else
		{
			std::cout << "char: impossible\n";
			std::cout << "int : impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float : "  << value << "0f\n";
			std::cout << "double : " << static_cast<double>(value) << "0\n";
			return;
		}
	}
	else {
		std::cout << "Invalid entry. Try again.\n";
	}
}
