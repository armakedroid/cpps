#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int n = 12;
	Zombie *smth = zombieHorde(n, "Jack");
	for (int i = 0; i < n; i++)
		smth[i].announce();
	delete[] smth;
}