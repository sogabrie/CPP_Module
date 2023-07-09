#pragma once
#ifndef __DOC_HPP__
#define __DOC_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog & other);
	Dog & operator=(const Dog & other);
	~Dog();

	std::string getType() const;
	void makeSound() const;
};

#endif