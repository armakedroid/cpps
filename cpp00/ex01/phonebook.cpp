#include "phonebook.hpp"

PhoneBook:: PhoneBook()
{
	this->count = 0;
	this->i = 0;
}

void PhoneBook::adding()
{
	std::string first;
	std::string last;
	std::string nick;
	std::string number;
	std::string secret;

	if (!std::cin.eof())
		std::cout<< "First name is ";
	std::getline(std::cin, first);
	if (!std::cin.eof())
		std::cout<< "Last Name is ";
	std::getline(std::cin, last);
	if (!std::cin.eof())
		std::cout<< "Nickname is ";
	std::getline(std::cin, nick);
	if (!std::cin.eof())
		std::cout<< "Phone number is ";
	std::getline(std::cin, number);
	if (!std::cin.eof())
		std::cout<< "Darkest secret is ";
	std::getline(std::cin, secret);

	if (first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
	{
		if (!std::cin.eof())
			std::cout<< "Please give all need information!"<< std::endl;
		return ;
	}
	contacts[i].create(first, last, nick, number, secret);
	i = (i + 1) % 8;
	if (count < 8)
		count++;
	std::cout<<"Done!"<<std::endl;		
}

std::string forTenSymb(std::string str)
{
	int j = 0;
	for (int i = 0; str[i]; i++)
		j++;
	if (j > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void PhoneBook::searching()
{
	if (!(this->count))
	{
		std::cout << "Not Contacts for searching!"<<std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|"
			  << std::setw(10) << forTenSymb(this->contacts[i].getFirstName()) << "|"
			  << std::setw(10) << forTenSymb(this->contacts[i].getLastName()) << "|"
			  << std::setw(10) << forTenSymb(this->contacts[i].getNickname()) << std::endl;
	}

	std::cout<<"Enter Index: ";
	int i;
	if (!(std::cin >> i))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<< "Not Valid Index!"<< std::endl;
		return ;
	}
	std::cin.ignore(10000, '\n');
	if (i < 0 || i >= this->count)
	{
		std::cout << "Not Valid Index!"<< std::endl;
		return ;
	}
	this->contacts[i].displayFull();
}
