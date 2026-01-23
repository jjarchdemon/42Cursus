/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:12:51 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/23 14:41:34 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : _index(0), _count(0)
{
}

/* helper functions -----------------------------*/

//truncate function
static std::string truncate(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

//handle non empty values function
static std::string getNonEmptyInput(std::string prompt)
{
	std::string	input;

	while (1)
	{
		std::cout << prompt;
		if(!std::getline(std::cin, input))
			return ("");
		if (input.length() > 0)
			return (input);
	}
}


/* member functions -----------------------------*/

void	Phonebook::addContact()
{
	int i;

	i = this->_index % 8;

	this->_contacts[i].setFirstName(getNonEmptyInput("Enter first name: "));
	this->_contacts[i].setLastName(getNonEmptyInput("Enter last name: "));
	this->_contacts[i].setNickName(getNonEmptyInput("Enter nickname: "));
	this->_contacts[i].setPhoneNumber(getNonEmptyInput("Enter phone number: "));
	this->_contacts[i].setDarkestSecret(getNonEmptyInput("Enter darkest secret: "));

	this->_index++;
	if (this->_count < 8)
		this->_count++;
	std::cout << "Contact added!" << std::endl;
}

void	Phonebook::displayContacts()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	int i = 0;
	while (i < this->_count)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncate(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncate(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncate(this->_contacts[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void Phonebook::searchContacts()
{
	int i;
	std::string input;

	this->displayContacts();
	if (this->_count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}

	std::cout << "Enter index to search: ";
	std::getline(std::cin, input);

	if (input.length() == 1 && std::isdigit(input[0]))
	{
		i = input[0] - '0';
		if (i >= 0 && i < this->_count)
		{
			std::cout << "Found contact!" << std::endl;
			std::cout << "First name: " << this->_contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << this->_contacts[i].getLastName() << std::endl;
			std::cout << "Nickname: " << this->_contacts[i].getNickName() << std::endl;
			std::cout << "Phone number: " << this->_contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->_contacts[i].getDarkestSecret() << std::endl;
			return;
		}
		std::cout << "Please enter a single digit between 0 and " << this->_count - 1 << std::endl;
	}
}