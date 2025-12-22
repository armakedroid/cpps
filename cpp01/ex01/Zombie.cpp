#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	cout<<this->name<<" destroyed."<<endl;
}

void Zombie::setName(string name)
{
	this->name = name;
}

void Zombie::announce()
{
	cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<endl;
}