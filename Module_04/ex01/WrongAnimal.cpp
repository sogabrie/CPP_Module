#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){}

WrongAnimal::WrongAnimal(std::string type) : type(type){}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){}

std::string WrongAnimal::getType() const { return (this->type); }

void WrongAnimal::makeSound() const
{
	std::cout << "Class WrongAnimal " << std::endl;
}