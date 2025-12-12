/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:28:12 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/11 13:37:30 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nEOF detected. Exiting.\n";
			break;
		}

		if (input == "ADD" || input == "Add" || input == "add")
			phoneBook.addContact();
		else if (input == "SEARCH" || input == "Search" || input == "search")
			phoneBook.searchContacts();
		else if (input == "EXIT" || input == "Exit" || input == "exit")
			break;
	}
	return 0;
}
