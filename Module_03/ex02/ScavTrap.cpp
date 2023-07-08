#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Constructor called FragTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "Constructor called ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->Energy_points > 0 && this->Energy_points > 0)
	{
		--this->Energy_points;
		std::cout << "ScavTrap " << this->Name << " attacks " << \
		target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "Trap can't do anything  it has no hit points" << std::endl;
	}
}

void ScavTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys" << std::endl;
}
