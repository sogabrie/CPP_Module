#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat a("AAA", 20);
		std::cout << a;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}