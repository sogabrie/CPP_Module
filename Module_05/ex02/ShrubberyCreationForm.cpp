#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
: AForm(name, "Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm(other.getName(), "Shrubbery Creation Form", 145, 137){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat const &bur)
{
	if (!bur.signForm(*this))
		throw MyException("ShrubberyCreationForm::GradeTooLowException");
	this->setSigned(true);
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSigned())
	{
		std::ofstream myfile(this->getName() + "_shrubbery");
		if (myfile.is_open())
		{
			for (size_t i = 0; i < 128; i++)
			{
				myfile << i << " = " << (char)i << std::endl;;
			}
			
		}
		else
		{
			myfile.close();
			throw MyException("ShrubberyCreationForm::ErrorFile");
		}
		myfile.close();
	}
	else
		throw MyException("ShrubberyCreationForm::GradeTooLowException");
	return (true);
}