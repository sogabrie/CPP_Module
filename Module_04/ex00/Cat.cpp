#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){}

Cat::Cat(const Cat &other) : Animal(other.Animal::getType()){}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.Animal::getType();
	return (*this);
}

Cat::~Cat(){}

std::string Cat::getType() const
{
	return (Animal::getType());
}

void Cat::makeSound() const
{
	std::cout << "Class Cat " << std::endl;
}
