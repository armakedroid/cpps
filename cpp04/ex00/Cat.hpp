#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &cp);
	Cat& operator=(const Cat &op);
	void makeSound() const;
	~Cat();
};