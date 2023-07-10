#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria *Cure::clone() const { return (new Cure(this->_type)); }

void Cure::use(ICharacter &target)
{
	std::cout << "Cure: \"* heals " << target.getName() << "s wounds *\"" << std::endl;
}
