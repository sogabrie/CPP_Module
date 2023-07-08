#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap a("A");
	FragTrap b("A_2");

	a.attack("C");
	b.attack("C_2");

	a.beRepaired(2);
	b.beRepaired(5);

	a.takeDamage(2);
	b.takeDamage(5);

	a.attack("C");
	b.attack("C_2");

	a.guardGate();
	b.highFivesGuys();

	return (0);
}