#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string name;
	int hit;
	int energy;
	int damage;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cp);
	ClapTrap& operator=(const ClapTrap& op);
	~ClapTrap();
	std::string getName();
	int getHit() const;
	int getEnergy() const;
	int getDamage() const;
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif