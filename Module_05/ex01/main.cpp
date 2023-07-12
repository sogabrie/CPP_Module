#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("AAA", 80);
		std::cout << a;
		Form b("Forem_1", 50, 50);
		b.beSigned(a);
		std::cout << b;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}