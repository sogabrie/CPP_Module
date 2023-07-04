#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
private:

	int number;
	static const int fractional_bits = 8;

public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif