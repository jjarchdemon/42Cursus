/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:02:12 by jambatt           #+#    #+#             */
/*   Updated: 2026/07/21 17:57:19 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mark const?

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> //cin cout
#include <iomanip>	//std::setw
#include <string>	//std::string

class Contact {

private:
    std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickName(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecret(std::string str);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};

#endif
