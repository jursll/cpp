#include "ScalarConverter.hpp"

bool ScalarConverter::isInt(const std::string& literal)
{
	if(literal.empty())
		return false;
	size_t i = 0;
	if(literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if(i == literal.length())
			return false;
	}
	size_t j = i;
	while (j < literal.length())
	{
		if(!std::isdigit(literal[j]))
			return false;
		j++;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	bool sawDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;

	if (literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if (i == literal.length())
			return false;
	}

	size_t j = i;
	while (j < literal.length())
	{
		if (std::isdigit(literal[j]))
		{
			if (sawDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[j] == '.')
		{
			if (sawDot == true)
				return false;
			sawDot = true;
		}
		else
		{
			return false;
		}
		j++;
	}

	return (sawDot && hasDigitBeforeDot && hasDigitAfterDot);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	bool sawDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;
	bool sawF = false;

	if (literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if (i == literal.length())
			return false;
	}

	size_t j = i;
	while (j < literal.length())
	{
		if (std::isdigit(literal[j]))
		{
			if (sawDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[j] == '.')
		{
			if (sawDot == true)
				return false;
			sawDot = true;
		}
		else if (literal[j] == 'f' && j == literal.length()-1)
		{
			sawF = true;
		}
		else
		{
			return false;
		}
		j++;
	}
	return (sawDot && hasDigitBeforeDot && hasDigitAfterDot && sawF);
}

