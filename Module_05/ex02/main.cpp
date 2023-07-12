#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm	*b = 0;
	AForm	*c = 0;
	AForm	*d = 0;

	try
	{

		b = new PresidentialPardonForm("Forem_1");
		c = new RobotomyRequestForm("Forem_2");
		d = new ShrubberyCreationForm("Forem_3");

		const Bureaucrat a("AAA", 45);
		std::cout << a;

		d->beSigned(a);
		a.executeForm(*d);

		c->beSigned(a);
		a.executeForm(*c);

		b->beSigned(a);
		a.executeForm(*b);

		std::cout << *b;
		std::cout << *c;
		std::cout << *d;

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete b;
	delete c;
	delete d;

	// system("leaks run");
	return (0);
}