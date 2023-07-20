// #include <iostream>
// #include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;
	for (int i = 0; i < 15; i++)
		a.push_back(i);
	std::vector<int>::iterator b = easyfind(a, 20);
	if (b != a.end())
		std::cout << "b = " << *b << "\n";
	else
		std::cout << "No  \n";
	return (0);
}