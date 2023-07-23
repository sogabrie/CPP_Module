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
	
private:
    ScalarConverter();
	ScalarConverter(const ScalarConverter & other);
	ScalarConverter& operator=(const ScalarConverter & other);
	~ScalarConverter();

	static TYPE_L	getType();

public:

	static void		print();

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

// std::ostream& operator<<(std::ostream& o, const ScalarConverter& pt);


#endif