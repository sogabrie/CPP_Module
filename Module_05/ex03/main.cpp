#include "Intern.hpp"

int main()
{
	AForm	*b = 0;
	AForm	*c = 0;
	AForm	*d = 0;

	try
	{
		Intern t;
		b = t.makeForm("Ppresidential request", "Form_1");
		c = t.makeForm("robotomy request", "Forma_2");
		d = t.makeForm("shrubbery requesta", "Forma_3");

		const Bureaucrat a("AAA", 4);
		std::cout << a;
		if (d)
		{
			d->beSigned(a);
			a.executeForm(*d);
			std::cout << *d;
		}

		if (c)
		{
			c->beSigned(a);
			a.executeForm(*c);
			std::cout << *c;
		}
		
		if (b)
		{
			b->beSigned(a);
			a.executeForm(*b);
			std::cout << *b;
		}
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