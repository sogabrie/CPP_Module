#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain("Cat brain");
}

Cat::Cat(const Cat &other) : Animal(other.Animal::getType())
{
	this->_brain = new Brain(*(other._brain));
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.Animal::getType();
	*(this->_brain) = *(other._brain);
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
}

std::string Cat::getType() const
{
	return (Animal::getType());
}

void Cat::makeSound() const
{
	std::cout << "Class Cat " << std::endl;
}
