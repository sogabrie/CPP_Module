#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
: AForm(name, "Robotomy Request Form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm(other.getName(), "Robotomy Request Form", 72, 45){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{ this->setSigned(other.getSigned()); return (*this);}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beSigned(Bureaucrat const &bur)
{
	if (!bur.signForm(*this))
		throw MyException("RobotomyRequestForm::GradeTooLowException");
	this->setSigned(true);
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSigned())
	{
		if (localTime->tm_sec % 2)
			std::cout << "That " << this->getName() << " has been robotomized\n";
		else
			std::cout << "That " << this->getName() << " the robotomy failed\n";
		
	}
	else
		throw MyException("RobotomyRequestForm::GradeTooLowException");
	return (true);
}