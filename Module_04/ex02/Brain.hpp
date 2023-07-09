#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain
{
protected:

	std::string ideas[100];
public:

	Brain();
	Brain(const std::string & ideas);
	Brain(const Brain & other);
	Brain & operator=(const Brain & other);
	~Brain();

	std::string * getIdeas();
	void setIdeas(const std::string & ideas);
};

#endif