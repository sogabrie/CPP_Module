#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template<typename T>
void	foo(T const & a)
{
	std::cout << a << std::endl;
}

template<typename T>
void iter(T * mas, size_t size, void(*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(mas[i]);
}

template<typename T>
void iter(T * mas, size_t size, void(*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(mas[i]);
}

#endif