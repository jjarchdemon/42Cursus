#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

private:
    std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number; //TODO logic for only number
	std::string secret;

    std::string getNonEmptyInput();

public:
    void assignContact();
    void displayDetails();

};

#endif
