#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	a.attack("C");
	a.beRepaired(2);
	a.takeDamage(2);
	a.attack("C");
	a.guardGate();
	return (0);
}