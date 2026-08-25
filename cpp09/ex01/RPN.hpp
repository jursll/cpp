#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluate(const std::string &expression);

private:
	std::stack<int> _stack;

	bool isOperator(char c) const;
	void applyOperator(char op);
};

#endif
