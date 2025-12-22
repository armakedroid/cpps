#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain *a;	
	public :
		Dog();
		Dog &operator=(const Dog &op);
		Dog (const Dog &op);
		void makeSound()const;
		~Dog();
};