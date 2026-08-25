#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int b = _stack.top(); _stack.pop();
	int a = _stack.top(); _stack.pop();

	if (op == '+') _stack.push(a + b);
	else if (op == '-') _stack.push(a - b);
	else if (op == '*') _stack.push(a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		_stack.push(a / b);
	}
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
			applyOperator(token[0]);
		else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
			_stack.push(token[0] - '0');
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
