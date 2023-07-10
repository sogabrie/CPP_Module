#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA__HPP__

#include <iostream>

class AMateria
{
protected:

public:
AMateria(std::string const & type);


std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const;
virtual void use(ICharacter& target);
};

#endif