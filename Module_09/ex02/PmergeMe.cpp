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
	(void)v;
	(void)c;
}


void PmergeMe::printEndTimeV()
{
	PmergeMe::_end_v = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = PmergeMe::_end_v - PmergeMe::_start_v;
	std::cout << "Time to process a range of 3000 elements with std::Vector : " << dur.count() << "\n";
}

void PmergeMe::printEndTimeL()
{
	PmergeMe::_end_l = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = PmergeMe::_end_l - PmergeMe::_start_l;
	std::cout << "Time to process a range of 3000 elements with std::List : " << dur.count() << "\n";
}

void PmergeMe::addDataV(char **v, size_t c)
{
	int a;

	for (size_t i = 0; i < (size_t)c ; i++)
	{
		a = std::stoi(v[i]);
		if (a < 0)
			throw MyException("Error");
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

static void sortInsert(std::vector<int> &mas)
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
	(void)smol;
	(void)larg;
	int number = 1;
	for (; !smol.size() ;)
	{
		number *=2;
		number -= 1;
		if (number >= smol.size())
			number = (int)smol.size() - 1;
	}
	
}

void PmergeMe::sortV(std::vector<int> &mas)
{
	std::vector<int> smol, larg;

	if (mas.size() == 2 || mas.size() == 3)
	{
		sortInsert(mas);
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

void PmergeMe::sortL()
{

}
