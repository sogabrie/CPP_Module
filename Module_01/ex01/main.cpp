#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int size = 10;

	Zombie *a = zombieHorde(size, "zombieHorde");
	for (int i = 0; i < size; i++)
		a[i].announce();
	// delete[] a;
	return (0);
}