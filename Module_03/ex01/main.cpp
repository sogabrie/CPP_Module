#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	a.attack("C");
	a.beRepaired(2);
	a.takeDamage(2);
	a.attack("C");
	return (0);
}