#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
    this->Name = name;
    this->ClapTrap::Name = name + "_clap_name";
    
    FragTrap::Hit_points = 100;
    ScavTrap::Energy_points = 50;
    FragTrap::Attack_damage = 30;
    
    std::cout << "DiamondTrap "<< this->Name << " Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap "<< this->Name << " Destructor called" << std::endl;
}

void    DiamondTrap::whoAmI( void ) 
{
    std::cout << "DiamondTrap name: " << this->Name << ", ClapTrap name: " << ClapTrap::Name << std::endl;
}