#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->fix_point = 0;
}

Fixed::Fixed(const Fixed& cp)
{
	std::cout<<"Copy constructor called"<<std::endl;
	fix_point = cp.fix_point;
}

Fixed& Fixed::operator=(const Fixed& op)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &op)
		fix_point = op.fix_point;
	return *this;
}

void Fixed::setRawBits(int new_fix)
{
	this->fix_point = new_fix;
}

int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->fix_point;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}