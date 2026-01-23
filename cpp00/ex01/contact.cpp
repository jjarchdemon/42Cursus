/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:02:19 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/22 22:25:51 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/************************ setters ************************/

void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNickName(std::string str)
{
	this->_nickName = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
}

/************************ getters ************************/

std::string	Contact::getFirstName()
{
	return (this->_firstName);
}

std::string	Contact::getLastName()
{
	return (this->_lastName);
}

std::string	Contact::getNickName()
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (this->_darkestSecret);
}