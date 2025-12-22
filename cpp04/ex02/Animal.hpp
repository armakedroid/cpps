#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string& t);
	Animal(const Animal& cp);
	Animal& operator=(const Animal& op);
	virtual std::string getType() const;
	virtual void makeSound() const = 0;
	virtual ~Animal();
};
