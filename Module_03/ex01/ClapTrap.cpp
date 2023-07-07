#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(0) , Hit_points(10) , Energy_points(10) , Attack_damage(0)
{
	std::cout << "Constructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name) , Hit_points(10) , Energy_points(10) , Attack_damage(0)
{
	std::cout << "Constructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int Hit, unsigned int Energy ,unsigned int Attack):
Name(name) , Hit_points(Hit) , Energy_points(Energy) , Attack_damage(Attack)
{
	std::cout << "Constructor called ClapTrap" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called ClapTrap" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->Energy_points > 0 && this->Energy_points > 0)
	{
		--this->Energy_points;
		std::cout << "ClapTrap " << this->Name << " attacks " << \
		target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "Trap can't do anything  it has no hit points" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->Attack_damage += amount;
	std::cout << "ClapTrap " << this->Name << " take Damage " << \
	this->Attack_damage << ", Attack damage " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)(this->Energy_points - amount) >= 0)
	{
		this->Energy_points -= amount;
		this->Hit_points += amount;
		std::cout << "ClapTrap " << this->Name << " be Repaired " << \
		this->Energy_points << ", Energy points " << this->Hit_points << " Hit points!" << std::endl;
	}
	else
	{
		std::cout << "Trap can't do anything  it has no hit points" << std::endl;
	}
}
