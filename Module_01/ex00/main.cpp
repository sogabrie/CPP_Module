#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	randomChump("stec zombi");
	Zombie *a = newZombie("NewZombi");
	a->announce();
	delete a;
	return (0);
}