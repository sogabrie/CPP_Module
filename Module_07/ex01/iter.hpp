#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template<typename T>
void	foo(T & a);

template<typename T>
void iter(T * mas, size_t size, void(*f)(T & a));

#endif