#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
: AForm("Shrubbery Creation Form", name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm("Shrubbery Creation Form", other.getName(), 145, 137){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat &bur)
{
	if (!bur.signForm(*this))
		throw MyException("ShrubberyCreationForm::GradeTooLowException");
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute())
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