#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other){ (void)other; return (*this); }

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &fr, std::string const &name)
{
	AForm	*ret = 0;
	size_t	i = 0;

	std::string ptfr[] = {"shrubbery request", "robotomy request", "Ppresidential request"};
	for (; fr != ptfr[i] && i < 3; i++);
	switch (i)
	{
	case 0:
		ret = new ShrubberyCreationForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	case 1:
		ret = new RobotomyRequestForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	case 2:
		ret = new PresidentialPardonForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	default:
		std::cout << "Error creates " << name << std::endl;
		break;
	}
	return (ret);
}
