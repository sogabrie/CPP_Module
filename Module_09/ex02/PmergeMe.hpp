#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <chrono>

template<class T>
class PmergeMe
{
private:
	T												_data;
	std::chrono::high_resolution_clock::time_point	_start;
public:
	PmergeMe(char ** v, size_t c);
	PmergeMe(const PmergeMe & other);
	PmergeMe & operator=(const PmergeMe & other);
	~PmergeMe();

	void	printEndTime(std::string ptr);
	void	printData();
	void	sort();

private:
	void addData(char ** v, size_t c);

	class MyException : public std::exception
	{
	private:
		const std::string _error;
	public:
		MyException(const std::string& error) : _error(error) {}
		~MyException() throw() {}
		const char * what () const throw () { return ((this->_error.data()));}
	};
};

#endif

template <class T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
	return (*this);
}