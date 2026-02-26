#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define TREE "    *\n   / \\ \n  / ^ \\ \n / ^ ^ \\ \n/^_^ ^_^\\ \n   | |"

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();

		const std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
