#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &cp);
	FragTrap& operator= (const FragTrap &op);
	void highFivesGuys(void);
	~FragTrap();
};
