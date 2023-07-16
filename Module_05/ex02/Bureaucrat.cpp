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

bool Bureaucrat::signForm(AForm const &fr) const
{
	if (this->_grade <= fr.getGradeToSign())
	{
		std::cout << this->_name << " signed " << fr.getName() << std::endl;
		return (true);
	}
	std::cout << this->_name << " couldnt sign " << fr.getName() << " because Grade Too Low Exception\n";
	return (false);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	if (form.execute(*this))
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	else
		std::cout << "ERROR \n" << this->getName() << " NOD executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".\n";
	return (o);
}

// -------->>  My Exception -------------->>

Bureaucrat::MyException::MyException(const std::string &error) : _error(error) {}

Bureaucrat::MyException::~MyException() throw() {}

const char *Bureaucrat::MyException::what() const throw() { return ((this->_error.data())); }
