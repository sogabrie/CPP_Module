#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Dellet Zombi " << this->name << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}