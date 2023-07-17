#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
: _status(EMTY), _statusInt(EMTY), _statusDouble(EMTY), 
_statusFloat(EMTY), _statusChar(EMTY) {}

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
	this->_status = OK;
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
		this->_status = EMTY;
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
	this->_statusFloat = OK;
	this->_double = OK;
	this->_int = OK;
	this->_char = OK;
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
		this->_statusFloat = OK;
		this->_double = OK;
		this->_int = OK;
		if (!(this->_double - static_cast<double>(this->_int)) && ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
		|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~')))
		{
			this->_char = static_cast<char>(this->_int);
			this->_char = OK;
		}
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
		this->_statusFloat = OK;
		this->_double = OK;
		this->_int = OK;
		if (!(this->_double - this->_int) && ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
		|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~')))
		{
			this->_char = static_cast<char>(this->_int);
			this->_char = OK;
		}
		else
			this->_statusChar = IMPOSSIBLE;
	}
}

void ScalarConverter::IntTo()
{
	this->_int = std::stoi(this->_ptr);
	this->_double = static_cast<double>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_statusFloat = OK;
	this->_double = OK;
	this->_int = OK;
	if ((this->_ptr[0] >= '!' && this->_ptr[0] <= '/') 
	|| (this->_ptr[0] >= ':' && this->_ptr[0] <= '~'))
	{
		this->_char = static_cast<char>(this->_int);
		this->_char = OK;
	}
	else
		this->_statusChar = IMPOSSIBLE;
}

TYPE_L ScalarConverter::fType()
{
	size_t i = 0;

	if (!this->_ptr.compare("-inf") || !this->_ptr.compare("+inf") || !this->_ptr.compare("nan"))
		return (DOUBLE);
	if (!this->_ptr.compare("-inff") || !this->_ptr.compare("+inff") || !this->_ptr.compare("nanf"))
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
	if (this->_ptr[i] < '0' || this->_ptr[i] > '9')
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	for (; i < this->_ptr.size() && ((this->_ptr[i] >= '0' && this->_ptr[i] <= '9')); ++i);
	if ((this->_ptr[i] == '.' && ((i + 1) == this->_ptr.size() || this->_ptr[i + 1] < '0' || 
	this->_ptr[i + 1] > '9')) || (this->_ptr[i] == 'f' && (i + 1) != this->_ptr.size()) || (this->_ptr[i] != '.' 
	&& this->_ptr[i] != 'f' && i != this->_ptr.size()))
	{
		this->_status = ERROR;
		throw MyException("ERROR TYPE");
	}
	++i;
	for (; i < this->_ptr.size() && ((this->_ptr[i] >= '0' || this->_ptr[i] <= '9') || this->_ptr[i] == 'f'); ++i)
	{
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

STATUS ScalarConverter::getStatus() const
{
	return (this->_status);
}

char ScalarConverter::getChar() const
{
	return (this->_char);
}

int ScalarConverter::getInt() const
{
	return (this->_int);
}

float ScalarConverter::getFloat() const
{
	return (this->_float);
}

double ScalarConverter::getDouble() const
{
	return (this->_double);
}

STATUS ScalarConverter::getCharStatus() const
{
	return (this->_statusChar);
}

STATUS ScalarConverter::getIntStatus() const
{
	return (this->_statusInt);
}

STATUS ScalarConverter::getFloatStatus() const
{
	return (this->_statusFloat);
}

STATUS ScalarConverter::getDoubleStatus() const
{
	return (this->_statusDouble);
}

// -------->>  My Exception -------------->>

ScalarConverter::MyException::MyException(const std::string &error) : _error(error) {}

ScalarConverter::MyException::~MyException() throw() {}

const char *ScalarConverter::MyException::what() const throw() { return ((this->_error.data())); }

// -------->> END  My Exception -------------->>

std::ostream &operator<<(std::ostream &o, const ScalarConverter &pt)
{
	if (pt.getStatus() == EMTY)
		return (o);

	o << "char: ";

	switch (pt.getCharStatus())
	{
	case EMTY:
		o << "EMTY";
		break;
	case OK:
		o << pt.getChar();
		break;
	case IMPOSSIBLE:
		o << "IMPOSSIBLE";
		break;
	default:
		break;
	}

	o << "\nint: ";

	switch (pt.getIntStatus())
	{
	case EMTY:
		o << "EMTY";
		break;
	case OK:
		o << pt.getInt();
		break;
	case IMPOSSIBLE:
		o << "IMPOSSIBLE";
		break;
	default:
		break;
	}

	switch (pt.getFloatStatus())
	{
	case EMTY:
		o << "\nfloat: EMTY";
		break;
	case OK:
		o << "\nfloat: " << pt.getFloat();
		break;
	default:
		break;
	}

	switch (pt.getDoubleStatus())
	{
	case EMTY:
		o << "\nDouble: EMTY\n";
		break;
	case OK:
		o << "\nDouble: " << pt.getDouble() << "\n";
		break;
	default:
		break;
	}

	switch (pt.getDoubleStatus())
	{
	case NAN:
		o << "\nfloat: nanf";
		o << "\nDouble: nan\n";
		break;
	case INF:
		o << "\nfloat: +inff";
		o << "\nDouble: +inf\n";
		break;
	case _INF:
		o << "\nfloat: -inff";
		o << "\nDouble: -inf\n";
		break;
	default:
		break;
	}
	return (o);
}
