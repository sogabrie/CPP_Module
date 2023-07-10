#include "MateriaSourc.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->_emty_slot[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_emty_slot[i])
			delete this->_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < 4 && m; i++)
	{
		if (!(this->_emty_slot[i]))
		{
			this->_emty_slot[i] = 1;
			this->_materias[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_materias[i]->getType == type)
			return (this->_materias[i]->clone());
	}
	return (0);
}
