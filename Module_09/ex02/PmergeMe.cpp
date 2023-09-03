#include "PmergeMe.hpp"

std::vector<int>								PmergeMe::_data_v;
std::list<int>									PmergeMe::_data_l;
std::chrono::high_resolution_clock::time_point	PmergeMe::_start_v = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point	PmergeMe::_start_l = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point	PmergeMe::_end_v = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point	PmergeMe::_end_l = std::chrono::high_resolution_clock::now();

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

void PmergeMe::run(char **v, size_t c)
{
	if (c < 2)
		throw MyException("Argument");

	PmergeMe::addDataV(v, c);
	PmergeMe::addDataL(v, c);

	std::cout << "Before: ";  
	for (size_t i = 0; i < PmergeMe::_data_v.size(); i++)
	{
		std::cout << PmergeMe::_data_v[i] << " ";
	}
	std::cout << "\n";

	PmergeMe::_start_v = std::chrono::high_resolution_clock::now();
	PmergeMe::sortV(PmergeMe::_data_v);
	PmergeMe::_end_v = std::chrono::high_resolution_clock::now();

	PmergeMe::_start_l = std::chrono::high_resolution_clock::now();
	PmergeMe::sortL(PmergeMe::_data_l);
	PmergeMe::_end_l = std::chrono::high_resolution_clock::now();

	std::cout << "After: "; 
	for (size_t i = 0; i < PmergeMe::_data_v.size(); i++)
	{
		std::cout << PmergeMe::_data_v[i] << " ";
	}
	std::cout << "\n";
	PmergeMe::printEndTimeV(c);
	PmergeMe::printEndTimeL(c);
}


void PmergeMe::printEndTimeV(int a)
{
	std::chrono::duration<double> dur = PmergeMe::_end_v - PmergeMe::_start_v;
	std::cout << "Time to process a range of " << a <<  " elements with std::Vector : " << (dur.count()) * 1000 << "\n";
}

void PmergeMe::printEndTimeL(int a)
{
	PmergeMe::_end_l = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = PmergeMe::_end_l - PmergeMe::_start_l;
	std::cout << "Time to process a range of "<< a << " elements with std::List : " << (dur.count()) * 1000  << "\n";
}

void PmergeMe::addDataV(char **v, size_t c)
{
	int a;

	for (size_t i = 0; i < (size_t)c ; i++)
	{
		a = std::stoi(v[i]);
		if (a <= 0)
			throw MyException("Argument");
		PmergeMe::_data_v.push_back(a);
	}
}

void PmergeMe::addDataL(char **v, size_t c)
{
	int a;

	for (size_t i = 0; i < (size_t)c ; i++)
	{
		a = std::stoi(v[i]);
		if (a < 0)
			throw MyException("Error");
		PmergeMe::_data_l.push_back(a);
	}
}

static void sortInsertV(std::vector<int> &mas)
{
	for (size_t i = 0; i + 1 < mas.size();)
	{
		if (mas[i] > mas[i + 1])
		{
			int t = mas[i];
			mas[i] = mas[i + 1];
			mas[i + 1] = t;
			i = 0;
		}
		else
			++i;
	}
}

static void sortV2(std::vector<int> &smol, std::vector<int> &larg)
{
	size_t number = 0;
	for (; smol.size() ;)
	{
		number +=1;
		number *=2;
		number -= 1;
		if (number >= smol.size())
			number = (int)smol.size() - 1;
		std::vector<int>::iterator it = larg.begin();
		for ( ; it != larg.end() && smol[number] > *it; ++it);
		larg.insert(it, smol[number]);
		it = smol.begin();
		std::advance(it ,number);
		smol.erase(it);
	}
	
}

void PmergeMe::sortV(std::vector<int> &mas)
{
	std::vector<int> smol, larg;

	if (mas.size() == 2 || mas.size() == 3)
	{
		sortInsertV(mas);
		return;
	}
	size_t i = 0;
	for (; i < mas.size() && i + 1 < mas.size(); i += 2)
	{
		if (mas[i] < mas[i + 1])
		{
			smol.push_back(mas[i]);
			larg.push_back(mas[i + 1]);
		}
		else
		{
			smol.push_back(mas[i + 1]);
			larg.push_back(mas[i]);
		}
	}
	if (i < mas.size())
	{
		smol.push_back(mas[i]);
	}
	PmergeMe::sortV(larg);
	sortV2(smol, larg);
	mas = larg;
}

static void sortInsertL(std::list<int> &mas)
{
	std::list<int>::iterator i = mas.begin();
	std::list<int>::iterator i2 = i;
	std::advance(i2, 1);
	for (; i2 != mas.end() && i != mas.end();)
	{
		if (*i > *i2)
		{
			int t = *i;
			*i = *i2;
			*i2 = t;
			i = mas.begin();
			i2 = i;
			std::advance(i2, 1);
		}
		else
		{
			std::advance(i, 1);
			i2 = i;
			std::advance(i2, 1);
		}
	}
}

static void sortL2(std::list<int> &smol, std::list<int> &larg)
{
	size_t number = 0;
	for (; smol.size() ;)
	{
		number +=1;
		number *=2;
		number -= 1;
		if (number >= smol.size())
			number = (int)smol.size() - 1;
		std::list<int>::iterator it = larg.begin();
		std::list<int>::iterator it_smol = smol.begin();
		std::advance(it_smol, number);
		for ( ; it != larg.end() && *it_smol > *it; ++it);
		larg.insert(it, *it_smol);
		it = smol.begin();
		std::advance(it ,number);
		smol.erase(it);
	}
	
}

void PmergeMe::sortL(std::list<int> &mas)
{
	std::list<int> smol, larg;
	if (mas.size() == 2 || mas.size() == 3)
	{
		sortInsertL(mas);
		return;
	}
	std::list<int>::iterator i = mas.begin();
	std::list<int>::iterator i2 = i;
	std::advance(i2 , 1);
	for (; i != mas.end() && i2 != mas.end(); std::advance(i , 2), i2 = i, std::advance(i2 , 1))
	{
		if (*i < *i2)
		{
			smol.push_back(*i);
			larg.push_back(*i2);
		}
		else
		{
			smol.push_back(*i2);
			larg.push_back(*i);
		}
	}
	if (i != mas.end())
	{
		smol.push_back(*i);
	}
	PmergeMe::sortL(larg);
	sortL2(smol, larg);
	mas = larg;
}
