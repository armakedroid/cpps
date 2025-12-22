#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int count;
	int i;
public:
	PhoneBook();
	void adding();
	void searching();
};

#endif