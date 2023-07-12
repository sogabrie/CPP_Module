#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
: AForm(name, "Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm(other.getName(), "Presidential Pardon Form", 25, 5){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{ this->setSigned(other.getSigned()); return (*this); }

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(Bureaucrat const &bur)
{
	if (!bur.signForm(*this))
		throw AForm::MyException("PresidentialPardonForm::GradeTooLowException");
	this->setSigned(true);
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSigned())
		std::cout << "that "<< this->getName()<< " has been pardoned by Zaphod Beeblebrox\n";
	else
		throw MyException("PresidentialPardonForm::GradeTooLowException");
	return (true);
}
