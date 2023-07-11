#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA__HPP__

#include <iostream>
#include "ICharacter.hpp"
class Cure;
class Ice;
class ICharacter;

class AMateria
{
protected:

	std::string _type;

public:

	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria & other);


	std::string const & getType() const; //Returns the materia type

	virtual ~AMateria();
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif