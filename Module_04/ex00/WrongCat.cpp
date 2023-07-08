#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat"){}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.WrongAnimal::getType()){}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.WrongAnimal::getType();
	return (*this);
}

WrongCat::~WrongCat(){}

std::string WrongCat::getType() const
{
	return (WrongAnimal::getType());
}

void WrongCat::makeSound() const
{
	std::cout << "WrongClass Cat " << std::endl;
}