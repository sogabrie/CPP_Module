#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
private:

	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat & operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string getName() const;
	int			getGrade() const;
	bool		signForm(std::string name, int a);

private:

	class MyException : public std::exception
	{
	private:
		const std::string _error;
	public:
		MyException(const std::string& error);
		~MyException() throw();
		const char * what () const throw ();
	};
};

std::ostream& operator<<(std::ostream &o, Bureaucrat& bur);

#endif