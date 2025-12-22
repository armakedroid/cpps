#include "Weapon.hpp"

Weapon::Weapon(string type) {setType(type);}

const string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(string str) 
{
	type = str;
}