#include "PmergeMe.hpp"

int main(int c, char ** v)
{
	try
	{
		PmergeMe<int > a(v,c);

		for (size_t i = 0; i < 10000; i++);
		

		a.printEndTime("aaaa");
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR " << e.what() << '\n';
	}
	
	return (0);
}