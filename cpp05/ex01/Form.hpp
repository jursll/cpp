#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_sgrade;
		const int			_egrade;

	public:
		Form();
		Form(const std::string name, const int sgrade, const int egrade);
		Form(Form const &src);
		Form& operator=(Form const &src);
		~Form();

		const std::string getName() const;
		bool getSigned() const;
		const int getSGrade()const;
		const int getEGrade() const;

		void beSigned(Bureaucrat &src);
		void signForm(Form& form);

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

std::ostream& operator<<(std::ostream& ostr, Form const& src);

#endif
