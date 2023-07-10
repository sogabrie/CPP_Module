#pragma once 
#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
public:
	Ice(std::string const & type);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif