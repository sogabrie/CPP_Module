#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:

	std::string name;
	Weapon *weap;

public:

	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &wear);
	void attack();
};

#endif