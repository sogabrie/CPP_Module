#include "PmergeMe.hpp"

int main(int c, char ** v)
{
	try
	{
		PmergeMe::run(v + 1, c - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR " << e.what() << '\n';
	}
	
	return (0);
}