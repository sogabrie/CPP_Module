#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : AMateria::type(type){}

std::string const &AMateria::getType() const { return (this->type); }

void AMateria::use(ICharacter &target)
{
	
}
