#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("AAA", 80);
		std::cout << a;
		AForm * b = new ShrubberyCreationForm("Forem_1");
		b->beSigned(a);
		std::cout << b;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}