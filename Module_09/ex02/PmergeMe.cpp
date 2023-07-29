#include "PmergeMe.hpp"
#include "PmergeMe.hpp"

template <class T>
PmergeMe<T>::PmergeMe(char **v, size_t c)
{
	(void)v;
	(void)c;
	this->_start = std::chrono::high_resolution_clock::now();
}

template <class T>
PmergeMe<T>::PmergeMe(const PmergeMe &other)
{
}

template <class T>
PmergeMe &PmergeMe<T>::operator=(const PmergeMe &other)
{
	return (*this);
}

template <class T>
PmergeMe<T>::~PmergeMe()
{
}

template <class T >
void PmergeMe<T>::printEndTime(std::string ptr)
{
	(void)ptr;
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur= end - this->_start;
	std::cout << dur.count() << "\n";
}

template <class T>
void PmergeMe<T>::printData()
{
}

template <class T>
void PmergeMe<T>::sort()
{
}

template class PmergeMe<int>;
template class PmergeMe<list<int>>;
template class PmergeMe<vector<int>>;
template class PmergeMe<deque<int>>;
template class PmergeMe<forward_list<int>>;
template class PmergeMe<array<int8_t>>;
