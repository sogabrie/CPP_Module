#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>

template <typename T>
typename T::iterator easyfind(T& con, int v);

#include "easyfind.tpp"
#endif
