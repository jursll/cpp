/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:18:32 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/11 13:57:11 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setContact()
{
	_FirstName = getNonEmptyStr("First name: ");
	_LastName = getNonEmptyStr("Last name: ");
	_Nickname = getNonEmptyStr("Nickname: ");
	_PhoneNumber = getValidPhoneNumber();
	_DarkestSecret = getNonEmptyStr("Darkest secret: ");
}

static std::string fieldFormat(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

void	Contact::displaySummary(int index) const
{
	std::cout	<< "|" << std::setw(10) << index << "|" << fieldFormat(_FirstName)
				<< "|" << fieldFormat(_LastName) << "|" << fieldFormat(_Nickname)
				<< "|" << std::endl;
}

void	Contact::displayFull() const
{
	std::cout << "First name: " << _FirstName << std::endl;
	std::cout << "Last name: " << _LastName << std::endl;
	std::cout << "Nickname: " << _Nickname << std::endl;
	std::cout << "Phone number: " << _PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << _DarkestSecret << std::endl;
}
