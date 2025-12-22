#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *first = new Zombie[N];
	for (int i = 0; i < N; i++)
		first[i].setName(name);
	return first;
}