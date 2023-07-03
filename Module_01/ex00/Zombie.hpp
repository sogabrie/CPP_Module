#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie
{
private:

	std::string name;

public:

	Zombie();
	Zombie(std::string name);
	~Zombie();

	void set_name(std::string name);

	void announce( void );

};

#endif
