#include "Fixed.hpp"

Fixed::Fixed()
{
	this->number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = other.number;
}

Fixed::Fixed(const float other)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(other * (1 << this->fractional_bits));
}

Fixed::Fixed(const int other)
{
	std::cout << "Int constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = other.number;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}