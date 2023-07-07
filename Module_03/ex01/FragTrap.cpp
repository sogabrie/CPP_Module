#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Constructor called FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "Constructor called FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called FragTrap" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->Energy_points > 0 && this->Energy_points > 0)
	{
		--this->Energy_points;
		std::cout << "FragTrap " << this->Name << " attacks " << \
		target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "Trap can't do anything  it has no hit points" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys" << std::endl;
}
