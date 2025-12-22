#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout<<"ScavTrap constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cp) : ClapTrap(cp)
{
	std::cout<<"ScavTrap copy constructor called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& op)
{
	std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
	if (this != &op)
		ClapTrap::operator=(op);
	return *this;
}

void ScavTrap::guardGate() const
{
	std::cout<<"ScavTrap "<<name<< " is now in Gate keeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->damage<<" points of damage!"<<std::endl;
		energy--;
	}
	else
		std::cout<<"ScavTrap "<<this->name<< " cannot attack: no energy or dead!" <<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap destructor called"<<std::endl;
}