#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (new Ice(this->_type)); }

void Ice::use(ICharacter &target)
{
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
