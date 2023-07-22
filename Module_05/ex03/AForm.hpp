#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
class Bureaucrat;

class AForm
{
private:
	const std::string 	_name;
	const std::string	_type;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_signed;
public:

	AForm(std::string name, std::string type, int grade_to_sign, int grade_to_execute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string 	getName() const;
	std::string		getType() const;
	bool			getSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	void			setSigned(bool a);
	virtual void	beSigned(Bureaucrat const & bur) = 0;
	virtual	bool	execute(Bureaucrat const & executor) const = 0;

protected:

	class MyException : private std::exception
	{
	private:
		const std::string _error;
	public:
		MyException(const std::string& error);
		~MyException() throw();
		const char * what () const throw ();

	};
	MyException a;
};

std::ostream& operator<<(std::ostream &o, const AForm& bur);

#endif