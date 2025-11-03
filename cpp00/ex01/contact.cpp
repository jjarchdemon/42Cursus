#include "contact.hpp"

std::string Contact::getNonEmptyInput() {
    std::string input;


    while (1) {
    	getline(std::cin, input);

        if (std::cin.eof()) {
            std::cout << "\nInput terminated.\n";
            return "";
        }

        if (!input.empty()) {
            break;  // valid input → exit loop
        }

        std::cout << "Field cannot be empty. Please enter again.\n";
        std::cout << "Enter value: ";
    }
    return input;
}

void Contact::assignContact() {
	std::cout << "Enter first name: ";
	first_name = getNonEmptyInput();
	std::cout << "Enter last name: ";
	last_name = getNonEmptyInput();
	std::cout << "Enter nick name: ";
	nick_name = getNonEmptyInput();
	std::cout << "Enter phone number: ";//TODO logic for only numbers
	phone_number = getNonEmptyInput();
	std::cout << "Enter your darkest secret: ";
	secret = getNonEmptyInput();
}


void Contact::displayDetails() {
	std::cout << "Showing contact... " << std::endl;
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nick name: " << nick_name << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
	}