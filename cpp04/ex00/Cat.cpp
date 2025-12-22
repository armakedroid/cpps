#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat& cp) : Animal(cp)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat& op)
{
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this != &op)
		Animal::operator=(op);
	return *this;
}

Cat::~Cat()
{
		std::cout<<"Cat destructor called"<<std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow\n";
}