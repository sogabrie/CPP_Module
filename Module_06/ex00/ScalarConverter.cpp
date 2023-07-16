#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
: _type(TYPE_L::EMTY), _status(STATUS::EMTY) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
: _type(other._type), _status(other._status), _ptr(other._ptr),
_int(other._int), _double(other._double), _float(other._float),
_char(other._char) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	this->_type = other._type;
	this->_status = other._status;
	this->_ptr = other._ptr;
	this->_int = other._int;
	this->_double = other._double;
	this->_float = other._float;
	this->_char = other._char;
	
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

TYPE_L ScalarConverter::getType(std::string str)
{
	return TYPE_L();
}

int ScalarConverter::getInt(std::string str)
{
	return 0;
}

char ScalarConverter::getChar(std::string str)
{
	return 0;
}

float ScalarConverter::getFloat(std::string str)
{
	return 0.0f;
}

double ScalarConverter::getDouble(std::string str)
{
	return 0.0;
}

void ScalarConverter::convert(std::string str)
{
}

void ScalarConverter::CharTo()
{
}

void ScalarConverter::FloatTo()
{
}

void ScalarConverter::DoubleTo()
{
}

void ScalarConverter::IntTo()
{
}

// -------->>  My Exception -------------->>

AForm::MyException::MyException(const std::string &error) : _error(error) {}

AForm::MyException::~MyException() throw() {}

const char *AForm::MyException::what() const throw() { return ((this->_error.data())); }

// -------->> END  My Exception -------------->>

std::ostream &operator<<(std::ostream &o, const ScalarConverter &pt)
{
	// TODO: вставьте здесь оператор return
}
