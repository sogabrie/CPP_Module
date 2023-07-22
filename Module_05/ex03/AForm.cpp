#include "AForm.hpp"

AForm::AForm(std::string name, std::string type, int grade_to_sign, int grade_to_execute) : 
_name(name), _type(type), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0) 
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw MyException("Form::GradeTooHighException");
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw MyException("Form::GradeTooLowException");
}

AForm::AForm(const AForm &other) : _name(other._name), _grade_to_sign(other._grade_to_sign), 
_grade_to_execute(other._grade_to_execute), _signed(other._signed) {}

AForm &AForm::operator=(const AForm &other)
{
	a.
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm(){}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string	AForm::getType() const
{
	return (this->_type);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

void AForm::setSigned(bool a)
{
	this->_signed = a;
}

// -------->>  My Exception -------------->>

AForm::MyException::MyException(const std::string &error) : _error(error) {}

AForm::MyException::~MyException() throw() {}

const char *AForm::MyException::what() const throw() { return ((this->_error.data())); }

std::ostream &operator<<(std::ostream &o, const AForm &bur)
{
	o << "AForm name  " << bur.getName() << " Signed " << 
	bur.getSigned() << " Grade To Sign " << bur.getGradeToSign()
	<< " Grade To Execute " << bur.getGradeToExecute() << std::endl;
	return (o);
}
