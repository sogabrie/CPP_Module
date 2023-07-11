#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat a("AAA", -200);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}