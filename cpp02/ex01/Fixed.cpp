#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fix_point = 0;
	std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const int fix)
{
	this->fix_point = fix << bit_num;
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float fFix)
{
	this->fix_point = roundf(fFix * (1 << bit_num));
	std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& cp)
{
	fix_point = cp.fix_point;
	std::cout<<"Copy constructor called"<<std::endl;
	std::cout<<"Copy assignment operator called"<<std::endl;
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

float Fixed::toFloat( void ) const
{
	float a = (float)fix_point / (1 << bit_num);
	return a;
}

int Fixed::toInt( void ) const
{
	return fix_point / (1 << bit_num);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}


Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}