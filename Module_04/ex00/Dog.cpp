#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &other) : Animal(other.Animal::getType()){}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	this->type = other.Animal::getType();
	return (*this);
}

Dog::~Dog(){}

std::string Dog::getType() const
{
	return (Animal::getType());
}

void Dog::makeSound() const
{
	std::cout << "Class Doc" << std::endl;
}
