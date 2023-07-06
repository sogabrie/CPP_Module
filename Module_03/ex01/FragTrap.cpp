#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Constructor called FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : a(name, 100, 50, 20) 
{
	std::cout << "Constructor called FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys" << std::endl;
}
