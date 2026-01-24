#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat& operator=(Bureaucrat const &src);
		~Bureaucrat();

		void GradeTooHighException() const;
		void GradeTooLowException() const;
		std::string getName() const;
		std::string getGrate() const;
		int incrementGrade(int grade);
		int decrementGrade(int grade);
};

#endif
