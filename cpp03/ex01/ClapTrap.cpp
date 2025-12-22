#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name)
{
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout<<"ClapTrap constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cp)
{
	std::cout<<"ClapTrap copy constructor called"<<std::endl;
	name = cp.name;
	hit = cp.hit;
	energy = cp.energy;
	damage = cp.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& op)
{
	std::cout<<"ClapTrap copy assignment operator called"<<std::endl;
	if (this != &op)
	{
		name = op.name;
		hit = op.hit;
		energy = op.energy;
		damage = op.damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->damage<<" points of damage!"<<std::endl;
		energy--;
	}
	else
		std::cout<<"ClapTrap "<<this->name<< " cannot attack: no energy or dead!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit <= 0)
	{
		std::cout << "ClapTrap " <<this->name<< " is already dead!"<<std::endl;
		return;
    }
	this->hit -= amount;
	if (this->hit < 0)
		this->hit = 0;
	std::cout<<"ClapTrap "<<this->name<<" takes damage "<<amount<<", hit equal to "<<this->hit<<" points."<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit <= 0)
	{
		std::cout << "ClapTrap " <<this->name<< " is already dead!"<<std::endl;
		return;
    }
	else if (this->energy > 0)
	{
		this->hit += amount;
		this->energy--;
		std::cout<<"ClapTrap "<<this->name<<" be repaired "<<amount<<", hit equal to "<<this->hit<<" points."<<std::endl;
	}
}

std::string ClapTrap::getName()
{
	return name;
}

int ClapTrap::getHit () const
{
	return this->hit;
}

int ClapTrap::getDamage() const
{
	return this->damage;
}

int ClapTrap::getEnergy() const
{
	return this->energy;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap destructor called"<<std::endl;
}