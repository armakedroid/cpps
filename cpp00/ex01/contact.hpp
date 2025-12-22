#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	void create(std::string first, std::string last, std::string nick, std::string number, std::string secret);
	void displayFull();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
};
