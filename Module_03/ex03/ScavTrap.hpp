#pragma once
#ifndef __ScavTrap_HPP__
#define __ScavTrap_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	void attack(const std::string& target);
	void highFivesGuys(void);
};


#endif