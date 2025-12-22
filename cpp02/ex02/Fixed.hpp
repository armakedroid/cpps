#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

class Fixed
{
private:
	int fix_point;
	static const int bit_num = 8;
public:
	Fixed();
	Fixed(const int fix);
	Fixed(const float fFix);
	Fixed(const Fixed& cp);
	Fixed& operator=(const Fixed& op);
	bool operator>(const Fixed& op) const;
	bool operator<(const Fixed& op) const;
	bool operator>=(const Fixed& op) const;
	bool operator<=(const Fixed& op) const;
	bool operator==(const Fixed& op) const;
	bool operator!=(const Fixed& op) const;
	Fixed operator+(const Fixed& op) const;
	Fixed operator-(const Fixed& op) const;
	Fixed operator*(const Fixed& op) const;
	Fixed operator/(const Fixed& op) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits(int new_fix);
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif