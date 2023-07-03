#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap)
{
	this->name = name;
	this->weap = &weap;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weap)
		std::cout << *(this->weap->getType());
	std::cout << std::endl;
}