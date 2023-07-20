#pragma once
#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__

template <class T, class R>
R easyfind(T con, int v)
{
	T::iterator it = con.begin();
	for (; it != a.end(); ++it)
	{
		if (*it == v)
			break;
	}
	return it;
}

#endif