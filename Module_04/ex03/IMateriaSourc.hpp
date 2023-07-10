#pragma once
#ifndef __IMATERIASOURC_HPP__
#define __IMATERIASOURC_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif