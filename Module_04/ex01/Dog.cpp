#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	this->_brain = new Brain("Dog brain");
}

Dog::Dog(const Dog &other) : Animal(other.Animal::getType())
{
	this->_brain = new Brain(*(other._brain));
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	this->type = other.Animal::getType();
	*(this->_brain) = *(other._brain);
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
}

std::string Dog::getType() const
{
	return (Animal::getType());
}

void Dog::makeSound() const
{
	std::cout << "Class Doc" << std::endl;
}
