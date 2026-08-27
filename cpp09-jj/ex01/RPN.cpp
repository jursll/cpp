#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
	}
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
	if (token.size() != 1)
		return (false);

	if (token[0] != '+'
		&& token[0] != '-'
		&& token[0] != '*'
		&& token[0] != '/')
		return (false);

	return (true);
}

bool RPN::applyOperation(char operation)
{
	if(_numbers.size() < 2)
		return false;

	int right = _numbers.top();
	_numbers.pop();
	int left = _numbers.top();
	_numbers.pop();

	int result;

	if(operation == '+')
		result = left + right;
	else if (operation == '-')
		result = left - right;
	else if (operation == '*')
		result = left * right;
	else if(operation == '/')
	{
		if (right == 0)
			return false;
		result = left / right;
	}
	else
		return false;

	_numbers.push(result);
	return true;
}

bool RPN::evaluate(const std::string& expression, int& result)
{
	while(!_numbers.empty())
		_numbers.pop();

	std::stringstream stream(expression);
	std::string token;

	while(stream >> token)
	{
		if(token[0] == 1 && std::isdigit(token[0]))
		{
			int number = token[0] - '0';
			_numbers.push(number);
		}
		else if (isOperator(token))
		{
			if (!applyOperation(token[0]))
				return (false);
		}
		else
			return false;
	}
	if(_numbers.size() != 1)
		return false;

	result = _numbers.top();
	return (true);
}
