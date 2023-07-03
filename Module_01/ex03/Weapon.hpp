#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon
{
private:

	std::string *type;

public:

	Weapon();
	Weapon(const std::string type);
	Weapon(const char* type);
	Weapon(const Weapon &weap);
	Weapon& operator=(const Weapon& other);
	~Weapon();

	const std::string* getType();
	void setType(std::string type);

};

#endif