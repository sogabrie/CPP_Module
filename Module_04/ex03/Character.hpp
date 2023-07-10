#pragma once 
#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string _name;
	AMateria*	_materias[4];
	size_t		_emty_slot[4];

public:
	Character(std::string name);
	Character(const Character & other);
	Character & operator=(const Character & other);
	~Character();
	std::string const & getName() const ;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif