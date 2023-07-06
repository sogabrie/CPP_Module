#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap
{
private:
	ClapTrap a;
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);
};


#endif