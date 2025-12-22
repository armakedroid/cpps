#include "Zombie.hpp"

Zombie::Zombie(string name) {
	this->name = name;
}

Zombie::~Zombie()
{
	cout<<this->name<<" destroyed."<<endl;
}

void Zombie::announce()
{
	cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<endl;
}