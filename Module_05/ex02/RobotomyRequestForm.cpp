#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
: AForm("Robotomy Request Form", name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm("Robotomy Request Form", other.getName(), 72, 45){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) { this->_signed = other.getSigned(); }

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beSigned(Bureaucrat &bur)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
}