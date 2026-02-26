#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_sgrade;
		const int			_egrade;

	public:
		AForm();
		AForm(const std::string name, const int sgrade, const int egrade);
		AForm(AForm const &src);
		AForm& operator=(AForm const &src);
		virtual ~AForm();

		const std::string getName() const;
		bool getSigned() const;
		int getSGrade()const;
		int getEGrade() const;

		void beSigned(Bureaucrat &src);
		void setSigned(bool sign);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("form is already signed");
				}
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return("form is not signed");
				}
		};
};

std::ostream& operator<<(std::ostream& ostr, AForm const& src);

#endif
