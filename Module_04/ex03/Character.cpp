#include "Character.hpp"

void Character::add_delet(AMateria *m)
{
	AMateria** cp;

	if (!m)
		return ;
	cp = new AMateria*[this-> _size_del_mate + 1];
	for (size_t i = 0; i < _size_del_mate; i++)
		cp[i] = _del_mater[i];
	delete[] _del_mater;
	_del_mater = cp;
	_del_mater[_size_del_mate] = m;
	++_size_del_mate;
}

Character::Character(std::string name) : _name(name), _del_mater(0), _size_del_mate(0) 
{
	for (size_t i = 0; i < 4; i++)
		this->_emty_slot[i] = 0;
}

Character::Character(const Character &other) :  _del_mater(0), _size_del_mate(0)
{
	this->_name = other._name;
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
		this->_name = other._name;
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
	for (size_t i = 0; i < this->_size_del_mate; i++)
		delete this->_del_mater[i];
	delete[] this->_del_mater;
}

std::string const &Character::getName() const { return (this->_name); }

void Character::equip(AMateria *m)
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
	add_delet(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_emty_slot[idx])
	{
		add_delet(this->_materias[idx]);
		this->_materias[idx] = 0;
		this->_emty_slot[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_emty_slot[idx])
		this->_materias[idx]->use(target);
	(void)target;
}
