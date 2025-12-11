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
	PhoneBook	pb;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "> Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin,str);
		if (str == "ADD")
			pb.add();
		else if (str == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
	}
	return 0;
}
