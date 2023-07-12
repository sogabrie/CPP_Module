#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
: AForm("Presidential Pardon Form", name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm("Presidential Pardon Form", other.getName(), 25, 5){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) { (void)other; return (*this); }

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(Bureaucrat &bur)
{
	if (!bur.signForm(*this))
		throw AForm::MyException("PresidentialPardonForm::GradeTooLowException");
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute())
		std::cout << "that "<< this->getName()<< " has been pardoned by Zaphod Beeblebrox\n";
	else
		throw MyException("PresidentialPardonForm::GradeTooLowException");
	return (true);
}
