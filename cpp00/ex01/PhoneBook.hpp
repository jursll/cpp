/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:18:32 by julrusse          #+#    #+#             */
/*   Updated: 2025/12/11 13:57:18 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _Contacts[8];
		int _Index;

	public:
		PhoneBook();
		~PhoneBook();
		void add(void);
		void search();
		void print(Contact contact);
		Contact getcontact(int index);
};

#endif
