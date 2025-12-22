#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Weapon
{
private:
	string type;
public:
	Weapon(string type);
	const string &getType() const;
	void setType(string str);
};

#endif