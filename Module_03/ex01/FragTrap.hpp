#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);
};


#endif