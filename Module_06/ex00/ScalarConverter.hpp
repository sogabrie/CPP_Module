#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

enum TYPE_L
{
	EMTY,
	NAN,
	INF,
	_INF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}

enum STATUS
{
	OK,
	EMTY,
	ERROR
}

class ScalarConverter
{
private:

	TYPE_L		_type;
	STATUS		_status;
	std::string	_ptr;
	int			_int;
	double		_dauble;
	float		_float;
	char		_char;

public:

    ScalarConverter();
	ScalarConverter(const ScalarConverter & other);
	ScalarConverter& operator=(const ScalarConverter & other);
	~ScalarConverter();

	TYPE_L	getType(std::string str);
	int		getInt(std::string str);
	char	getChar(std::string str);
	float	getFloat(std::string str);
	double	getDouble(std::string str);

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