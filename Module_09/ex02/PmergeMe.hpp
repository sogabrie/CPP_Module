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

class PmergeMe
{
private:
	static std::vector<int>									_data_v;
	static std::list<int>									_data_l;
	static std::chrono::high_resolution_clock::time_point	_start_v;
	static std::chrono::high_resolution_clock::time_point	_start_l;
	static std::chrono::high_resolution_clock::time_point	_end_v;
	static std::chrono::high_resolution_clock::time_point	_end_l;

	PmergeMe();
	PmergeMe(const PmergeMe & other);
	PmergeMe & operator=(const PmergeMe & other);
	~PmergeMe();

	static void printEndTimeV();
	static void printEndTimeL();
	static void addDataV(char ** v, size_t c);
	static void addDataL(char ** v, size_t c);

	static void sortL();
	static void sortV(std::vector<int> &mas);

public:

	static void run(char **v, size_t c);

private:

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
