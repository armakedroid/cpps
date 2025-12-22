#pragma once

#include "Animal.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	public :
		Brain();
		Brain(const Brain &op);
		Brain &operator=(const Brain &op);
		~Brain();
};