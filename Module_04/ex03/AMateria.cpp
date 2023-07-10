#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type){}

// AMateria::AMateria()
// {
// }

// AMateria::AMateria(const AMateria &other)
// {
// 	this->_type = other._type;
// }

std::string const &AMateria::getType() const { return (this->_type); }

AMateria::~AMateria(){}

// AMateria* AMateria::clone() const
// {
//     return ((AMateria*)this);
// }

void AMateria::use(ICharacter &target)
{
	(void)target;	
}
