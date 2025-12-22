#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout<<"FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp)
{
	std::cout<<"FragTrap copy constructor called"<<std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& op)
{
	std::cout<<"FragTrap copy assignment operator called"<<std::endl;
	if (this != &op)
		ClapTrap::operator=(op);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout<<"FragTrap "<<name<<" requests ✋"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap destructor called"<<std::endl;
}