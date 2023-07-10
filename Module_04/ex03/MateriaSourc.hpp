#pragma once
#ifndef __MATERIASOURC_HPP__
#define __MATERIASOURC_HPP__

#include "IMateriaSourc.hpp"

class MateriaSource : public IMateriaSource
{
public:
	~MateriaSource() {}
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif