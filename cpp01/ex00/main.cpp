#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie(std::string name);

int main()
{
	randomChump("Johnson");
	Zombie *smth = newZombie("Jack");
	smth->announce();
	delete(smth);
}