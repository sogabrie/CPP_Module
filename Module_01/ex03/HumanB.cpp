#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weap = 0;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weap)
{
	this->weap = &weap;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weap)
		std::cout << *(this->weap->getType());
	std::cout << std::endl;
}