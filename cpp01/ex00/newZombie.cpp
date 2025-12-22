#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *first = new Zombie(name);
	return first;
}