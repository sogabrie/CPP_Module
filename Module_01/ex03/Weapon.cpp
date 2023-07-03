#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = 0;
}

Weapon::Weapon(const std::string type)
{
	this->type = new std::string(type);
}

Weapon::Weapon(const char* type)
{
	this->type = new std::string(type);
}

Weapon::Weapon(const Weapon &weap)
{
	if (this->type)
		delete this->type;
	this->type = new std::string(*(weap.type));
}

Weapon& Weapon::operator= (const Weapon& other)
{
	if (this->type)
		delete this->type;
	this->type = new std::string(*(other.type));
	return (*this);
}

Weapon::~Weapon()
{
	if (this->type)
		delete this->type;
}

const std::string *Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	if (this->type)
		delete this->type;
	this->type = new std::string(type);
}