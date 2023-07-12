#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other){ (void)other; return (*this); }

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &fr, std::string const &name)
{
	AForm	*ret = 0;
	std::string ptfr[] = {"shrubbery request", "robotomy request", "Ppresidential request"};
	AForm	*a[] = 
			{
				new ShrubberyCreationForm(name),
				new RobotomyRequestForm(name),
				new PresidentialPardonForm(name)
			};
	for (size_t i = 0; i < 3; i++)
	{
		if (fr == ptfr[i])
			ret = a[i];
		else
			delete a[i];
	}

	if (ret)
		std::cout << "Intern creates " << name << std::endl;
	else
		std::cout << "Error creates " << name << std::endl;
	return (ret);
}
