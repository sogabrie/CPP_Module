#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw MyException("Bureaucrat::GradeTooHighException");
	if (grade > 150)
		throw MyException("Bureaucrat::GradeTooLowException");
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

std::ostream &operator<<(std::ostream &o, Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".\n";
	return (o);
}

// -------->>  My Exception -------------->>

Bureaucrat::MyException::MyException(const std::string &error) : _error(error) {}

Bureaucrat::MyException::~MyException() throw() {}

const char *Bureaucrat::MyException::what() const throw() { return ((this->_error.data())); }
