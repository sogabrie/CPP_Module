#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "FragTrap Constructor called" << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys( void ) 
{
    std::cout << "FragTrap " << this->Name << " High Fives Guys." << std::endl;
}