/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:18:38 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/11 13:23:03 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _Count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact()
{
	int index = _Count % 8;
	_Contacts[index].setContact();
	_Count++;
	std::cout << "Contact added at index " << index + 1 << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (_Count == 0)
	{
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < (_Count < 8 ? _Count : 8); i++)
		_Contacts[i].displaySummary(i + 1);


	std::cout << "Enter an index to display contact's full info: ";
	std::string input;
	std::getline(std::cin, input);

	std::istringstream iss(input);
	int index;
	if (!(iss >> index) || index < 1 || index > _Count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	_Contacts[index -1].displayFull();
}
