#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <chrono>

template<class T>
class PmergeMe
{
private:
	T	_data;
	std::chrono::high_resolution_clock::time_point _start;
public:
	PmergeMe(char ** v, size_t c);
	// PmergeMe(const PmergeMe & other);
	// PmergeMe & operator=(const PmergeMe & other);
	~PmergeMe();

	void	printEndTime(std::string ptr);
	// void	printData();
	// void	sort();
};

#endif