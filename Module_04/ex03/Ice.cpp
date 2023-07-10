#include "Ice.hpp"

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (new Ice(this->_type)); }

void Ice::use(ICharacter &target)
{
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
