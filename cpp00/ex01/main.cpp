#include "contact.hpp"



int main()
{
	Contact contact;
	std::cout << "This is phonebook. Add your contacts!" << std::endl;
	std::cout << "Commands to use: ADD, SEARCH and EXIT" << std::endl;
	
	// some kind of loop which looks for SEARCH ADD EXIT
	std::string command;
	while (1)
	{
		std::cout << "Enter command: ";
		getline(std::cin, command);

		if (command == "ADD")
		{
			//ask for details
			//TODO logic top check for empty fields
			contact.assignContact();
		}
		else if (command == "SEARCH")
		{
			contact.displayDetails();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting phonebook program...";
			break;
		}
		else //just ignore everything else
			std::cout << "Invalid command. ADD, SEARCH or EXIT" << std::endl;
	}
	return 0;

}
