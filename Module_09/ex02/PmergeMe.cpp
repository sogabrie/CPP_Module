#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	(void)v;
	(void)c;
	this->_start = std::chrono::high_resolution_clock::now();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	return (*this);
}

void PmergeMe::run(char **v, size_t c)
{
}


void PmergeMe::printEndTime(std::string ptr)
{
	(void)ptr;
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur= end - this->_start;
	std::cout << dur.count() << "\n";
}

void PmergeMe::addData(char **v, size_t c)
{
	int a;

	for (size_t i = 0; i < (size_t)c ; i++)
	{
		a = std::stoi(v[i]);
		if (a < 0)
			throw MyException("Error");
		this->_data.push_back(a);
	}
	
}



