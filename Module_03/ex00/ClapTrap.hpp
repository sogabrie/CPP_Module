#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
private:

	std::string		Name;
	unsigned int	Hit_points;
	unsigned int	Energy_points;
	unsigned int	Attack_damage;

public:

	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif