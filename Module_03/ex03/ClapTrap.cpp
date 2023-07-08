#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name) : Name(name) , Hit_points(10) , Energy_points(10) , Attack_damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& other) 
{
	this->Name = other.Name;
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
	return *this;
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
