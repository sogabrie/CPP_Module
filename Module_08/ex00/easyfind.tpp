#pragma once
#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__

template <typename T>
typename T::iterator easyfind(T& con, int v)
{
	typename T::iterator it = con.begin();
	for (; it != con.end(); ++it)
	{
		if (*it == v)
			return (it);
	}
	return (it);
}

#endif