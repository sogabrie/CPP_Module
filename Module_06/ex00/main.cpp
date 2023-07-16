#include "ScalarConverter.hpp"

int main()
{
	try
	{
		ScalarConverter a;
		a.convert("0000000000000000000000000045.0f");
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}