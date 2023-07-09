#pragma once
#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(const WrongCat & other);
	WrongCat & operator= (const WrongCat & other);
	~WrongCat();

	std::string getType() const;
	void makeSound() const;
};

#endif