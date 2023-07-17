#include "ScalarConverter.hpp"

int main(int c, char** v)
{
	if (c != 2)
	{
		return (0);
	}
	try
	{
		ScalarConverter a;
		a.convert(v[1]);
		switch (a.getType())
		{
		case CHAR:
			std::cout << "CHAR \n";
			break;
		case INT:
			std::cout << "INT \n";
			break;
		case DOUBLE:
			std::cout << "DOUBLE \n";
			break;
		case FLOAT:
			std::cout << "FLOAT\n";
			break;
		default:
			std::cout << "Vochmek \n";
			break;
		}
		std::cout << a;
	}
	catch(const ScalarConverter::MyException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}