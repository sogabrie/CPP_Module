#include <iostream>
#include "Harl.hpp"

int main(int c, char **v)
{
	if (c != 2)
		std::cout << "ERROR argumen count" << std::endl;
	Harl a;
	a.complain(v[1]);
	return (0);
}