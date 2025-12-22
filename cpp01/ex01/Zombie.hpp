#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Zombie
{
private:
	string name;
public:
	Zombie();
	~Zombie();
	void announce();
	void setName(string name);
};

#endif