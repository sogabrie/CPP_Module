#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other._type) {}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return (AMateria*)(new Cure()); }

void Cure::use(ICharacter &target)
{
	std::cout << "Cure: \"* heals " << target.getName() << "s wounds *\"" << std::endl;
}
