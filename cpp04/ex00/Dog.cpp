#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &op) : Animal(op)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &op)
{
	if (this != &op)
		Animal::operator=(op);
	std::cout<<"Dog operator constructor called"<<std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout<<"WOOF"<<std::endl;
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}


