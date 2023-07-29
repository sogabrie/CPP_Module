#include "RPN.hpp"

int main(int c, char ** v)
{
	if (c != 2)
	{
		std::cout << "Error Argument\n";
		return (0);
	}
	try
	{
		RPN a;
		a.rpn(v[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}