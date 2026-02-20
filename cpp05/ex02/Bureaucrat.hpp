#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat& operator=(Bureaucrat const &src);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &src);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade is too low");
				}
		};
};

std::ostream& operator<<(std::ostream& ostr, Bureaucrat const& src);

#endif
