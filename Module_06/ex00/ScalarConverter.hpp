#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

enum TYPE_L
{
	_EMTY,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

enum STATUS
{
	NAN,
	INF,
	_INF,
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

	STATUS	getStatus() const;

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	STATUS	getCharStatus() const;
	STATUS	getIntStatus() const;
	STATUS	getFloatStatus() const;
	STATUS	getDoubleStatus() const;

	void 	convert(std::string str);

private:

	void	CharTo();
	void	FloatTo();
	void	DoubleTo();
	void	IntTo();
	TYPE_L	fType();

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