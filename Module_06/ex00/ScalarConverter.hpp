#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

enum TYPE_L
{
	NAN,
	INF,
	_INF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

enum STATUS
{
	OK,
	EMTY,
	ERROR,
	IMPOSSIBLE
};

class ScalarConverter
{
private:

	TYPE_L		_type;
	STATUS		_status;
	std::string	_ptr;
	int			_int;
	STATUS		_statusInt;
	double		_double;
	STATUS		_statusDouble;
	float		_float;
	STATUS		_statusFloat;
	char		_char;
	STATUS		_statusChar;

public:

    ScalarConverter();
	ScalarConverter(const ScalarConverter & other);
	ScalarConverter& operator=(const ScalarConverter & other);
	~ScalarConverter();

	TYPE_L	getType();

	// void	print=Char();
	// void	print=Float();
	// void	print=Double();
	// void	print=Int();

	void 	convert(std::string str);

private:

	void	CharTo();
	void	FloatTo();
	void	DoubleTo();
	void	IntTo();

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

std::ostream& operator<<(std::ostream& o, const ScalarConverter& pt);


#endif