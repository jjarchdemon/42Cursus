#include <iostream>
#include <string>

class Contact {

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number; //int?
	std::string secret;

public:
	void addContact() {
		std::cout << "Enter first name: ";
		getline(std::cin, first_name);
		std::cout << "Enter last name: ";
		getline(std::cin, last_name);
		std::cout << "Enter nick name: ";
		getline(std::cin, nick_name);
		std::cout << "Enter phonenumber: ";
		getline(std::cin, phone_number);
		std::cout << "Enter your darkest secret: ";
		getline(std::cin, secret);
	}

	void displayDetails() {
		std::cout << "First name: " << first_name << std::endl;
		std::cout << "Last name: " << last_name << std::endl;
		std::cout << "Nick name: " << nick_name << std::endl;
		std::cout << "Phone number: " << phone_number << std::endl;
		std::cout << "First name: " << secret << std::endl;

	}
};
