#include "Brain.hpp"

Brain::Brain(){}

Brain::Brain(const std::string & ideas)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = ideas;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(){}

std::string * Brain::getIdeas()
{
	return (this->ideas);
}

void Brain::setIdeas(const std::string &ideas)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = ideas;
}
