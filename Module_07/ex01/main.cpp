
#include "iter.hpp"

int main()
{
	int a[] = {1 , 2 , 3, 4, 5};
	iter(a, 5, foo);
	std::string b[] = {"a", "b", "c" , "d", "e"};
	iter(b, 5, foo);
	return (0);
}