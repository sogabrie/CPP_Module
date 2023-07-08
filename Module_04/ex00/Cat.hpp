#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(const Cat & other);
	Cat & operator= (const Cat & other);
	~Cat();

	std::string getType() const;
	void makeSound() const;
};

#endif