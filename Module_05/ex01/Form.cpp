#include "Form.hpp"

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name),
{
}

Form::Form(const Form &other)
{
}

Form &Form::operator=(const Form &other)
{
	// TODO: вставьте здесь оператор return
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return std::string();
}

bool Form::getSigned() const
{
	return false;
}

int Form::getGradeToSign() const
{
	return 0;
}

int Form::getGradeToExecute() const
{
	return 0;
}

// -------->>  My Exception -------------->>

Form::MyException::MyException(const std::string &error) : _error(error) {}

Form::MyException::~MyException() throw() {}

const char *Form::MyException::what() const throw() { return ((this->_error.data())); }