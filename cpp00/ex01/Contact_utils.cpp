/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:18:32 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/11 13:57:11 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getNonEmptyStr(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt ;
		std::getline(std::cin, input);

		if (!input.empty())
			return input;

		std::cout << "Input can't be empty. Try again.\n";
	}
}

std::string Contact::getValidPhoneNumber()
{
	std::string input;

	while (true)
	{
		input = getNonEmptyStr("Phone number: ");

		bool valid = true;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
			{
				valid = false;
				break;
			}
		}
		if (valid)
			return input;
		std::cout << "Phone number must contain only digits. Try again.\n";
	}
}
