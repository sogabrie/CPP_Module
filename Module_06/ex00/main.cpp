#include "ScalarConverter.hpp"

int main(int c, char** v)
{
	if (c != 2)
	{
		return (0);
	}
	try
	{
		ScalarConverter::convert(v[1]);
		// std::cout << ScalarConverter::;
	}
	catch(const ScalarConverter::MyException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Overflow" << '\n';
	}
	
}