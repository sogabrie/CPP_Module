// #include <iostream>
// #include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;
	for (int i = 1; i < 15; i++)
		a.push_back(i);
	// std::vector<int>::iterator b = easyfind(a, 5);
	int b = easyfind(a, 5);
	std::cout << "b = " << b << "\n";
	return (0);
}