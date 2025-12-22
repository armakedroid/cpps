#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(const Brain &op)
{
	for(int i = 0; i < 100; i++)
		ideas[i] = op.ideas[i];
	std::cout<<"Brain copy constructor called"<<std::endl;
}

Brain &Brain::operator=(const Brain &op)
{
	std::cout<<"Brain operator constructor called"<<std::endl;
	if (this != &op)
		for(int i = 0; i < 100; i++)
			ideas[i] = op.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout<< "Brain destructor called"<<std::endl;
}