#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
: AForm("Robotomy Request Form", name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm("Robotomy Request Form", other.getName(), 72, 45){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) { (void)other; return (*this); }

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beSigned(Bureaucrat &bur)
{
	if (!bur.signForm(*this))
		throw MyException("RobotomyRequestForm::GradeTooLowException");
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	if (executor.getGrade() <= this->getGradeToExecute())
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