#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
: _status(EMTY) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
: _type(other._type), _status(other._status), _ptr(other._ptr),
_int(other._int), _statusInt(other._statusInt), _double(other._double), 
_statusDouble(other._statusDouble), _float(other._float), _statusFloat(other._statusFloat),
_char(other._char), _statusChar(other._statusChar) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	this->_type = other._type;
	this->_status = other._status;
	this->_ptr = other._ptr;
	this->_int = other._int;
	this->_statusInt = other._statusInt;
	this->_double = other._double;
	this->_statusDouble = other._statusDouble;
	this->_float = other._float;
	this->_statusFloat = other._statusFloat;
	this->_char = other._char;
	this->_statusChar = other._statusChar;

	return (*this);
}

ScalarConverter::~ScalarConverter() {}

TYPE_L ScalarConverter::getType()
{
	size_t i = 0;

	if (this->_status == OK)
		return (this->_type);
	if (!this->_ptr.size())
	{
		this->_status = EMTY;
		return (this->_type);
	}
	if (this->_status == ERROR)
		throw MyException("ERROR TYPE");
	if (this->_ptr.size() == 1 && ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
	|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~')))
	{
		return (CHAR);
	}
	if (this->_ptr[i] != '-' && this->_ptr[i] != '+' && (this->_ptr[i] < '0' || this->_ptr[i] > '9'))
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	std::cout << "aaa_1\n"; 
	if (this->_ptr[i] == '-' || this->_ptr[i] == '+')
		i++;
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	std::cout << "aaa_2\n"; 
	if (this->_ptr[i] < '0' || this->_ptr[i] > '9')
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	std::cout << "aaa_3\n";
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	for (; i < this->_ptr.size() && ((this->_ptr[i] >= '0' && this->_ptr[i] <= '9')); ++i);
	std::cout << "aaa_4\n";
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	if ((this->_ptr[i] == '.' && ((i + 1) == this->_ptr.size() || this->_ptr[i + 1] < '0' || 
	this->_ptr[i + 1] > '9')) || (this->_ptr[i] == 'f' && (i + 1) != this->_ptr.size()) || (this->_ptr[i] != '.' 
	&& this->_ptr[i] != 'f' && i != this->_ptr.size()))
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	std::cout << "aaa_5\n"; 
	++i;
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	for (; i < this->_ptr.size() && ((this->_ptr[i] >= '0' || this->_ptr[i] <= '9') || this->_ptr[i] == 'f'); ++i)
	{
		std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
		if (this->_ptr[i] == 'f' && (i + 1) != this->_ptr.size())
		{
			this->_status = ERROR;
			throw MyException("ERROR TYPE");
		}
		if (this->_ptr[i] < '0' && this->_ptr[i] > '9' && this->_ptr[i] != 'f')
		{
			this->_status = ERROR;
			throw MyException("ERROR TYPE");
		}
	}
	std::cout << "aaa_6\n";
	if (this->_ptr[this->_ptr.size() - 1] == 'f')
		return (FLOAT);
	for (size_t i = 0; i < this->_ptr.size(); i++)
	{
		if (this->_ptr[i] == '.')
			return (DOUBLE);
	}
	

	return (INT);
}

void ScalarConverter::convert(std::string str)
{
	this->_ptr = str;
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

ScalarConverter::MyException::MyException(const std::string &error) : _error(error) {}

ScalarConverter::MyException::~MyException() throw() {}

const char *ScalarConverter::MyException::what() const throw() { return ((this->_error.data())); }

// -------->> END  My Exception -------------->>

std::ostream &operator<<(std::ostream &o, const ScalarConverter &pt)
{
	(void)pt;
	return (o);
}
