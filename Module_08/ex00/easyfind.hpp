#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <vector>

// template <class T>
// T<int>::iterator easyfind(T<int> con, int v);

template <class T>
int easyfind(T con, int v)
{
	// R it = con.begin();
	int i = 0;
	for (; i < con.size(); ++i)
	{
		if (con[i] == v)
			return (i);
	}
	return (-1);
}

// #include "easyfind.tpp"
#endif
