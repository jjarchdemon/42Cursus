/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:02:29 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/23 14:48:20 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


int main()
{
	Phonebook phonebook;

	std::cout << "This is phonebook. Add your contacts!" << std::endl;
	std::cout << "Commands to use: ADD, SEARCH and EXIT" << std::endl;
	
	std::string command;
	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			phonebook.addContact();	
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Exiting phonebook program...";
			break;
		}
		else
			std::cout << "Invalid command. ADD, SEARCH or EXIT" << std::endl;
	}
	return 0;
}
