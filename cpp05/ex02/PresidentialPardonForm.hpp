#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm& operator=(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm();

		const std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
