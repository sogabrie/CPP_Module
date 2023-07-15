#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

enum TYPE_L
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}

class ScalarConverter
{
private:
    ScalarConverter();

	static TYPE_L	getType(std::string str);
	static int		getInt(std::string str);
	static char		getChar(std::string str);
	static float	getFloat(std::string str);
	static double	getDouble(std::string str);

	static int		CharToInt(char str);
	static int		FloatToInt(float str);
	static int		DoubleToInt(double str);

	static char		IntToChar(int str);
	static char		FloatToChar(float str);
	static char		DoubleToChar(double str);

	static float	IntleToFloat(int str);
	static float	CharToFloat(char str);
	static float	DoubleToFloat(double str);

	static double	IntleToDouble(int str);
	static double	CharToDouble(char str);
	static double	FloatToDouble(float str);
	
public:
    ~ScalarConverter();

	static void convert(std::string str);
};


#endif