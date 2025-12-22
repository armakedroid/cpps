#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog &operator=(const Dog &op);
		Dog (const Dog &op);
		void makeSound()const;
		~Dog();
};