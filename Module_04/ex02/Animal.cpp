#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(std::string type) : type(type){}

Animal::Animal(const Animal& other) : type(other.type){}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Animal::~Animal(){}

std::string Animal::getType() const { return (this->type); }
