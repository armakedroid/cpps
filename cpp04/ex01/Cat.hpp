#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
private :
	Brain *a;
public:
	Cat();
	Cat(const Cat &cp);
	Cat& operator=(const Cat &op);
	void makeSound() const;
	~Cat();
};