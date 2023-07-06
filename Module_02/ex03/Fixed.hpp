/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:22:55 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/06 16:22:56 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	Fixed	();
	Fixed	(const Fixed &other);
	Fixed	(const float other);
	Fixed	(const int other);
	Fixed&	operator=(const Fixed &other);
	~Fixed	();

	bool    operator>(const Fixed &other) const ;
	bool    operator<(const Fixed &other) const ;
	bool    operator>=(const Fixed &other) const ;
	bool    operator<=(const Fixed &other) const ;
	bool    operator==(const Fixed &other) const ;
	bool    operator!=(const Fixed &other) const ;

	Fixed   operator+(const Fixed &other) const ;
	Fixed   operator-(const Fixed &other) const ;
	Fixed   operator*(const Fixed &other) const ;
	Fixed   operator/(const Fixed &other) const ;

	Fixed&  operator++();
	Fixed   operator++(int);
	Fixed&  operator--();
	Fixed   operator--(int);

    static Fixed&		min(Fixed &a, Fixed &b);
    static const Fixed&	min(const Fixed &a, const Fixed &b);
    static Fixed&		max(Fixed &a, Fixed &b);
    static const Fixed&	max(const Fixed &a, const Fixed &b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<< (std::ostream& o, Fixed const& i);

#endif