#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->a = new Brain;
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat& cp) : Animal(cp)
{
	this->a = new Brain(*cp.a);
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat& op)
{
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this != &op)
	{
		delete (this->a);
		this->a = new Brain(*op.a);
		Animal::operator=(op);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow\n";
}

Cat::~Cat()
{
	delete (this->a);
	std::cout<<"Cat destructor called"<<std::endl;
}