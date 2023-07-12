#include "Form.hpp"

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : 
_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0) 
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw MyException("Form::GradeTooHighException");
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw MyException("Form::GradeTooLowException");
}

Form::Form(const Form &other) : _name(other._name), _grade_to_sign(other._grade_to_sign), 
_grade_to_execute(other._grade_to_execute), _signed(other._signed) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form(){}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

void Form::setSigned(bool a)
{
	this->_signed = a;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (!bur.signForm(this->getName(), this->getGradeToSign()))
		throw MyException("Form::GradeTooLowException");
	this->setSigned(true);
}

// -------->>  My Exception -------------->>

Form::MyException::MyException(const std::string &error) : _error(error) {}

Form::MyException::~MyException() throw() {}

const char *Form::MyException::what() const throw() { return ((this->_error.data())); }

std::ostream &operator<<(std::ostream &o, Form &bur)
{
	o << "Form name  " << bur.getName() << " Signed " << 
	bur.getSigned() << " Grade To Sign " << bur.getGradeToSign()
	<< " Grade To Execute " << bur.getGradeToExecute() << std::endl;
	return (o);
}
