#pragma once
#ifndef __MATERIASOURC_HPP__
#define __MATERIASOURC_HPP__

#include "IMateriaSourc.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_materias[4];
	size_t		_emty_slot[4];
public:
	MateriaSource();
	~MateriaSource();
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif