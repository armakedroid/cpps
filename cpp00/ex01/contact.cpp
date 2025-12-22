#include "contact.hpp"

Contact::Contact() {}

void Contact::create(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	this->firstName = first;
	this->lastName = last;
	this->nickname = nick;
	this->phoneNumber = number;
	this->darkestSecret = secret;
}

void Contact::displayFull()
{
	std::cout<<"First Name: "<< this->firstName << std::endl;
	std::cout<<"Last Name: "<<this->lastName<<std::endl;
	std::cout<<"Nickname: "<<this->nickname<<std::endl;
	std::cout<<"Phone Number: "<<this->phoneNumber<<std::endl;
	std::cout<<"Darkest Secret: "<<this->darkestSecret<<std::endl;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}