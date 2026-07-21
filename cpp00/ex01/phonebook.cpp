/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:12:51 by jambatt           #+#    #+#             */
/*   Updated: 2026/07/21 18:10:13 by jambatt          ###   ########.fr       */
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

	std::cout << prompt;
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		return ("");
	}
	while (input.empty())
	{
		std::cout << "Input cannot be empty. Please try again: " << prompt;
		if(!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return ("");
		}
	}
	return (input);
}


/* member functions -----------------------------*/

void	Phonebook::addContact()
{
	int i;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	i = this->_index % 8;

	firstName = getNonEmptyInput("Enter first name: ");
	if (firstName.empty())
		return;
	
	lastName = getNonEmptyInput("Enter last name: ");
	if (lastName.empty())
		return;
	
	nickName = getNonEmptyInput("Enter nickname: ");
	if (nickName.empty())
		return;
	
	phoneNumber = getNonEmptyInput("Enter phone number: ");
	if (phoneNumber.empty())
		return;

	darkestSecret = getNonEmptyInput("Enter darkest secret: ");
	if (darkestSecret.empty())
		return;

	this->_contacts[i].setFirstName(firstName);
	this->_contacts[i].setLastName(lastName);
	this->_contacts[i].setNickName(nickName);
	this->_contacts[i].setPhoneNumber(phoneNumber);
	this->_contacts[i].setDarkestSecret(darkestSecret);

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