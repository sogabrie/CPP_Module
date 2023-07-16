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

Bureaucrat &Bureaucrat::operator++()
{
	if (this->_grade > 1)
		--this->_grade;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat a(*this);
	if (this->_grade > 1)
		--this->_grade;
    return (a);
}

Bureaucrat &Bureaucrat::operator--()
{
	if (this->_grade < 150)
		++this->_grade;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat a(*this);
	if (this->_grade < 150)
		++this->_grade;
    return (a);
}

std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

bool Bureaucrat::signForm(std::string name, int a)
{
	if (this->_grade <= a)
	{
		std::cout << this->_name << " signed " << name << std::endl;
		return (true);
	}
	std::cout << this->_name << " couldnt sign " << name << " because Grade Too Low Exception\n";
	return (false);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".\n";
	return (o);
}

// -------->>  My Exception -------------->>

Bureaucrat::MyException::MyException(const std::string &error) : _error(error) {}

Bureaucrat::MyException::~MyException() throw() {}

const char *Bureaucrat::MyException::what() const throw() { return ((this->_error.data())); }
