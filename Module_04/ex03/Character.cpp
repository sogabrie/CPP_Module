#include "Character.hpp"

Character::Character(std::string name) : _name(name) , _emty_slot(0){}

Character::Character(const Character &other)
{
	this->_name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (other._emty_slot[i])
		{
			this->_emty_slot[i] = other._emty_slot[i];
			this->_materias[i] = other._materias[i]->clone();
		}
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (other._emty_slot[i])
			{
				this->_emty_slot[i] = other._emty_slot[i];
				delete this->_materias[i];
				this->_materias[i] = other._materias[i]->clone();
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_emty_slot[i])
			delete this->_materias[i];
	}
	
}

std::string const &Character::getName() const { return (this->_name); }

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
}
