#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>

class Form
{
private:
	const std::string 	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
public:

	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

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

std::ostream& operator<<(std::ostream &o, Form& bur);

#endif