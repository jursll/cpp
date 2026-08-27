#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <cctype>

class RPN
{
	private:
		std::stack<int> _numbers;

		bool isOperator(const std::string& token) const;
		bool applyOperation(char operation);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		bool evaluate(const std::string& expression, int& result);
};

#endif
