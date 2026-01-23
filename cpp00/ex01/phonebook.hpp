/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:18:59 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/23 13:19:14 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

private:
	Contact	_contacts[8];
	int		_index;
	int		_count;

public:
	Phonebook();
	void	addContact();
	void	searchContacts();
	void	displayContacts();
};

#endif
