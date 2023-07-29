#include "PmergeMe.hpp"

int main(int c, char ** v)
{
	(void)c;
	for (size_t i = 0; i < (size_t)c; i++)
	{
		std::cout << v[i] << " ";
	}
	return (0);
}