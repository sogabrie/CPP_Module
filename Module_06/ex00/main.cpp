#include "ScalarConverter.hpp"

int main()
{
	try
	{
		ScalarConverter a;
		a.convert("060.1f");
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}