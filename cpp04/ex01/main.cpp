#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	Dog *i = new Dog();
	Dog *j = new Dog(*i);
	delete j;
	delete i;
	return 0;
}