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
	for (typename T::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	{
		std::cout << " " << *it;
	}
	
}

template <class T>
void PmergeMe<T>::sort()
{
}

template <class T>
void PmergeMe<T>::addData(char **v, size_t c)
{
	int a;

	for (size_t i = 0; i < (size_t)c ; i++)
	{
		a = std::stoi(v[i]);
		if (a < 0)
			throw MyException("");
		this->_data.push_back(a);
	}
	
}

template class PmergeMe<std::list<int> >;
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
