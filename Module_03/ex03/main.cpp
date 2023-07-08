#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ScavTrap a("A");
	// FragTrap b("A_2");
	DiamondTrap c("A_3");
	

	// a.attack("C");
	// b.attack("C_2");
	c.attack("C_3");

	// a.beRepaired(2);
	// b.beRepaired(5);
	c.beRepaired(7);

	// a.takeDamage(2);
	// b.takeDamage(5);
	c.takeDamage(7);

	// a.attack("C");
	// b.attack("C_2");
	c.attack("C_3");

	// a.guardGate();
	// b.highFivesGuys();
	c.whoAmI();

	return (0);
}