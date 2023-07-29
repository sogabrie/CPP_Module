#include "PmergeMe.hpp"

int main(int c, char ** v)
{
	PmergeMe<int> a(v,c);

	for (size_t i = 0; i < 1000000000; i++);
	

	a.printEndTime("aaaa");
	return (0);
}