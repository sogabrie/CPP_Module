#pragma once 
#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
	Cure(std::string const & type);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif