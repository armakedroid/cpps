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
	Zombie(string name);
	~Zombie();
	void announce();
};

#endif