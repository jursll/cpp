/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:22:56 by julrusse          #+#    #+#             */
/*   Updated: 2025/11/28 14:06:07 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	NoArgs()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

std::string	ToUpper(std::string str)
{
	for (unsigned long i = 0; i < str.size(); i++)
		str[i] = std::toupper((unsigned char)(str[i]));

	return str;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		NoArgs();
		return 1;
	}

	for(int i = 1; i < ac; i++)
		std::cout << ToUpper(av[i]);

	std::cout << std::endl;

	return 0;
}
