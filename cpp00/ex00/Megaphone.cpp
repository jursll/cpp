/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:22:56 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/12 20:44:21 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	noArgs()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

std::string	toUpper(std::string str)
{
	for (unsigned long i = 0; i < str.size(); i++)
		str[i] = std::toupper((unsigned char)(str[i]));

	return str;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		noArgs();
		return 1;
	}

	for(int i = 1; i < ac; i++)
		std::cout << toUpper(av[i]);

	std::cout << std::endl;

	return 0;
}
