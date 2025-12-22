#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->a = new Brain;
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &op) : Animal(op)
{
	this->a = new Brain(*op.a);
	std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &op)
{
	if (this != &op)
	{
		delete (this->a);
		this->a = new Brain(*op.a);
		Animal::operator=(op);
	}
	std::cout<<"Dog operator constructor called"<<std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout<<"WOOF"<<std::endl;
}

Dog::~Dog()
{
	delete (this->a);
	std::cout<<"Dog destructor called"<<std::endl;
}


