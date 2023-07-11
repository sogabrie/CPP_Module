#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other._type) {}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (AMateria*)(new Ice()); }

void Ice::use(ICharacter &target)
{
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
