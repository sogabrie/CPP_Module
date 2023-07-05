#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int number;
	static const int fractional_bits = 8;

public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed(const float other);
	Fixed(const int other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<< (std::ostream& o, Fixed const& i);

#endif