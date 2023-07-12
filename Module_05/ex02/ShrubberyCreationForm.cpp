#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
: AForm("Presidential Pardon Form", name, 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm("Presidential Pardon Form", other.getName(), 145, 137){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) { this->_signed = other.getSigned(); }

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(Bureaucrat &bur)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
}