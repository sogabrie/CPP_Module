
#include "iter.hpp"

int main()
{
	int a[] = {1 , 2 , 3, 4, 5};
	iter(a, 5, foo);
	std::string b[] = {"a", "b", "c" , "d", "e"};
	iter(b, 5, foo);
	return (0);
}

template<typename T>
void	foo(T & a)
{
	std::cout << a << std::endl;
}

template<typename T>
void iter(T * mas, size_t size, void(*f)(T & a))
{
	for (size_t i = 0; i < size; i++)
		f(mas[i]);
}