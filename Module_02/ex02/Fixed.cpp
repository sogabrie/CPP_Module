/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:22:15 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/09 16:10:19 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->number = 0;
}

Fixed::Fixed(const Fixed &other)
{
	this->number = other.number;
}

Fixed::Fixed(const float other)
{
	this->number = roundf(other * (1 << this->fractional_bits));
}

Fixed::Fixed(const int other)
{
	this->number = other * (1 << this->fractional_bits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->number) / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->number / (1 << this->fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->number = other.number;
	return (*this);
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->number > other.number);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->number >= other.number);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->number != other.number);
}


Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	++this->number;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed a(*this);
	++this->number;
    return (a);
}

Fixed &Fixed::operator--()
{
	--this->number;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed a(*this);
	--this->number;
    return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

int Fixed::getRawBits(void) const
{
	return (this->number);
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
