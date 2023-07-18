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

	static TYPE_L		_type;
	static STATUS		_status;
	static std::string	_ptr;
	static int			_int;
	static STATUS		_statusInt;
	static double		_double;
	static STATUS		_statusDouble;
	static float		_float;
	static STATUS		_statusFloat;
	static char			_char;
	static STATUS		_statusChar;
	
public:
    ScalarConverter();
	ScalarConverter(const ScalarConverter & other);
	ScalarConverter& operator=(const ScalarConverter & other);
	~ScalarConverter();

	static TYPE_L	getType();

public:

	static STATUS	getStatus();

	static char		getChar();
	static int		getInt();
	static float	getFloat();
	static double	getDouble();

	static STATUS	getCharStatus();
	static STATUS	getIntStatus();
	static STATUS	getFloatStatus();
	static STATUS	getDoubleStatus();

	static void 	convert(std::string str);

private:

	static void		CharTo();
	static void		FloatTo();
	static void		DoubleTo();
	static void		IntTo();
	static TYPE_L	fType();

public:

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

// STATUS	ScalarConverter::_status = EMTY;
// STATUS	ScalarConverter::_statusInt = EMTY;
// STATUS	ScalarConverter::_statusDouble = EMTY;
// STATUS	ScalarConverter::_statusFloat = EMTY;
// STATUS	ScalarConverter::_statusChar = EMTY;
// TYPE_L		ScalarConverter::_type = _EMTY;
// std::string	ScalarConverter::_ptr = 0;
// int			ScalarConverter::_int = 0;
// double		ScalarConverter::_double = 0;
// float		ScalarConverter::_float = 0;
// char			ScalarConverter::_char = 0;

// std::ostream& operator<<(std::ostream& o, const ScalarConverter& pt);


#endif