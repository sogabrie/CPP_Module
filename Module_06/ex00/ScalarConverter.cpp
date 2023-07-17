#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
: _status(EMTY), _statusInt(OK), _statusDouble(OK), 
_statusFloat(OK), _statusChar(OK) {}

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
	if (this->_status == OK)
		return (this->_type);
	if (!this->_ptr.size())
	{
		this->_status = EMTY;
		return (_EMTY);
	}
	if (this->_status == ERROR)
		throw MyException("ERROR TYPE");
	return (this->fType());
}

void ScalarConverter::convert(std::string str)
{
	this->_ptr = str;
	this->_type = this->getType();
	switch (this->_type)
	{
	case CHAR:
		this->CharTo();
		break;
	case DOUBLE:
		this->DoubleTo();
		break;
	case INT:
		this->IntTo();
		break;
	case FLOAT:
		this->FloatTo();
		break;
	default:
		std::cout << "Emty class \n";
		break;
	}
}

void ScalarConverter::CharTo()
{
	this->_char = this->_ptr[0];
	this->_double = static_cast<double>(this->_char);
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
}

void ScalarConverter::FloatTo()
{
	if (this->_ptr.compare("-inff"))
	{
		this->_statusFloat = _INF;
		this->_double = _INF;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else if (this->_ptr.compare("+inff"))
	{
		this->_statusFloat = INF;
		this->_double = INF;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else if (this->_ptr.compare("nanf"))
	{
		this->_statusFloat = NAN;
		this->_double = NAN;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else
	{
		this->_float = std::stof(this->_ptr);
		this->_double = static_cast<double>(this->_float);
		this->_int = static_cast<int>(this->_float);
		if (!(this->_double - static_cast<double>(this->_int)) && ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
		|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~')))
			this->_char = static_cast<char>(this->_int);
		else
			this->_statusChar = IMPOSSIBLE;
	}
}

void ScalarConverter::DoubleTo()
{
	if (this->_ptr.compare("-inf"))
	{
		this->_statusFloat = _INF;
		this->_double = _INF;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else if (this->_ptr.compare("+inf"))
	{
		this->_statusFloat = INF;
		this->_double = INF;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else if (this->_ptr.compare("nan"))
	{
		this->_statusFloat = NAN;
		this->_double = NAN;
		this->_int = IMPOSSIBLE;
		this->_char = IMPOSSIBLE;
	}
	else
	{
		this->_double = std::stod(this->_ptr);
		this->_float = static_cast<double>(this->_double);
		this->_int = static_cast<int>(this->_double);
		if (!(this->_double - this->_int) && ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
		|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~')))
			this->_char = static_cast<char>(this->_int);
		else
			this->_statusChar = IMPOSSIBLE;
	}
}

void ScalarConverter::IntTo()
{
	this->_int = std::stoi(this->_ptr);
	this->_double = static_cast<double>(this->_int);
	this->_float = static_cast<float>(this->_int);
	if ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
	|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~'))
		this->_char = static_cast<char>(this->_int);
	else
		this->_statusChar = IMPOSSIBLE;
}

TYPE_L ScalarConverter::fType()
{
	size_t i = 0;

	if (this->_ptr.compare("-inf") || this->_ptr.compare("+inf") || this->_ptr.compare("nan"))
		return (DOUBLE);
	if (this->_ptr.compare("-inff") || this->_ptr.compare("+inff") || this->_ptr.compare("nanf"))
		return (FLOAT);
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
	if (this->_ptr[i] == '-' || this->_ptr[i] == '+')
		i++;
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	if (this->_ptr[i] < '0' || this->_ptr[i] > '9')
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	std ::cout << "i = " << i << " size == " << this->_ptr.size() << std::endl;
	for (; i < this->_ptr.size() && ((this->_ptr[i] >= '0' && this->_ptr[i] <= '9')); ++i);
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
	if (this->_ptr[this->_ptr.size() - 1] == 'f')
		return (FLOAT);
	for (size_t i = 0; i < this->_ptr.size(); i++)
	{
		if (this->_ptr[i] == '.')
			return (DOUBLE);
	}
	this->_status = OK;
	return (INT);
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
