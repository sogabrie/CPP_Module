#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<class T>
class PmergeMe
{
private:
	T	_data;
public:
	PmergeMe(const char ** v);
	PmergeMe(const PmergeMe & other);
	PmergeMe & operator=(const PmergeMe & other);
	~PmergeMe();

	void	printEndTime(std::string ptr);
};

#endif