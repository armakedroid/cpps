#include "Animal.hpp"

Animal::Animal() {
	std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(const std::string& t) : type(t) {
	std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(const Animal& cp)
{
	type = cp.type;
	std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal& Animal::operator=(const Animal& op)
{
	std::cout<<"Animal copy assignment operator called"<<std::endl;
	if (this != &op)
		type = op.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called"<<std::endl;
}