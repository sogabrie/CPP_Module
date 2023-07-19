#include "ScalarConverter.hpp"

STATUS		ScalarConverter::_status = EMTY;
STATUS		ScalarConverter::_statusInt = EMTY;
STATUS		ScalarConverter::_statusDouble = EMTY;
STATUS		ScalarConverter::_statusFloat = EMTY;
STATUS		ScalarConverter::_statusChar = EMTY;
TYPE_L		ScalarConverter::_type = _EMTY;
std::string	ScalarConverter::_ptr;
int			ScalarConverter::_int = 0;
double		ScalarConverter::_double = 0;
float		ScalarConverter::_float = 0;
char		ScalarConverter::_char = 0;

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

TYPE_L ScalarConverter::getType()
{
	if (!_ptr.size())
	{
		_status = EMTY;
		return (_EMTY);
	}
	if (_status == ERROR)
		throw MyException("ERROR TYPE");
	return (fType());
}

void ScalarConverter::print()
{
	if (getStatus() == EMTY)
		return ;

	std::cout << "char: ";
	switch (getCharStatus())
	{
	case EMTY:
		std::cout << "EMTY";
		break;
	case OK:
		std::cout << "'" << getChar() << "'";
		break;
	case IMPOSSIBLE:
		std::cout << "impossible";
		break;
	default:
		break;
	}

	std::cout << "\nint: ";

	switch (getIntStatus())
	{
	case EMTY:
		std::cout << "EMTY";
		break;
	case OK:
		std::cout << getInt();
		break;
	case IMPOSSIBLE:
		std::cout << "impossible";
		break;
	default:
		break;
	}

	switch (getFloatStatus())
	{
	case EMTY:
		std::cout << "\nfloat: EMTY";
		break;
	case OK:
		std::cout << "\nfloat: " << getFloat() << "f";
		break;
	default:
		break;
	}

	switch (getDoubleStatus())
	{
	case EMTY:
		std::cout << "\nDouble: EMTY\n";
		break;
	case OK:
		std::cout << "\nDouble: " << getDouble() << "\n";
		break;
	default:
		break;
	}

	switch (getDoubleStatus())
	{
	case NAN:
		std::cout << "\nfloat: nanf";
		std::cout << "\nDouble: nan\n";
		break;
	case INF:
		std::cout << "\nfloat: +inff";
		std::cout << "\nDouble: +inf\n";
		break;
	case _INF:
		std::cout << "\nfloat: -inff";
		std::cout << "\nDouble: -inf\n";
		break;
	default:
		break;
	}
}

void ScalarConverter::convert(std::string str)
{
	ScalarConverter::_ptr = str;
	ScalarConverter::_type = ScalarConverter::getType();
	ScalarConverter::_status = OK;
	switch (ScalarConverter::_type)
	{
	case CHAR:
		ScalarConverter::CharTo();
		break;
	case DOUBLE:
		ScalarConverter::DoubleTo();
		break;
	case INT:
		ScalarConverter::IntTo();
		break;
	case FLOAT:
		ScalarConverter::FloatTo();
		break;
	default:
		ScalarConverter::_status = EMTY;
		std::cout << "Emty class \n";
		break;
	}
}

void ScalarConverter::CharTo()
{
	_char = _ptr[0];
	_double = static_cast<double>(_char);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_statusFloat = OK;
	_statusDouble = OK;
	_statusInt = OK;
	_statusChar = OK;
}

void ScalarConverter::FloatTo()
{
	if (!_ptr.compare("-inff"))
	{
		_statusFloat = _INF;
		_statusDouble = _INF;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else if (!_ptr.compare("+inff"))
	{
		_statusFloat = INF;
		_statusDouble = INF;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else if (!_ptr.compare("nanf"))
	{
		_statusFloat = NAN;
		_statusDouble = NAN;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else
	{
		_float = std::stof(_ptr);
		_double = static_cast<double>(_float);
		if (_double > INT_MAX || _double < INT_MIN)
			_statusInt = IMPOSSIBLE;
		else
		{
			_int = static_cast<int>(_double);
			_statusInt = OK;
		}
		_statusFloat = OK;
		_statusDouble = OK;
		if (!(_double - static_cast<double>(_int)) && ((_int >= '!' && _int <= '/') 
		|| (_int >= ':' && _int <= '~')))
		{
			_char = static_cast<char>(_int);
			_statusChar = OK;
		}
		else
			_statusChar = IMPOSSIBLE;
	}
}

void ScalarConverter::DoubleTo()
{
	if (!_ptr.compare("-inf"))
	{
		_statusFloat = _INF;
		_statusDouble = _INF;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else if (!_ptr.compare("+inf"))
	{
		_statusFloat = INF;
		_statusDouble = INF;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else if (!_ptr.compare("nan"))
	{
		_statusFloat = NAN;
		_statusDouble = NAN;
		_statusInt = IMPOSSIBLE;
		_statusChar = IMPOSSIBLE;
	}
	else
	{
		_double = std::stod(_ptr);
		_float = static_cast<double>(_double);
		if (_double > INT_MAX || _double < INT_MIN)
			_statusInt = IMPOSSIBLE;
		else
		{
			_int = static_cast<int>(_double);
			_statusInt = OK;
		}
		_statusFloat = OK;
		_statusDouble = OK;
		if (!(_double - _int) && ((_int >= '!' && _int <= '/') 
		|| (_int >= ':' && _int <= '~')))
		{
			_char = static_cast<char>(_int);
			_statusChar = OK;
		}
		else
			_statusChar = IMPOSSIBLE;
	}
}

void ScalarConverter::IntTo()
{
	_int = std::stoi(_ptr);
	_double = static_cast<double>(_int);
	_float = static_cast<float>(_int);
	_statusFloat = OK;
	_statusDouble = OK;
	_statusInt = OK;
	if ((_int >= '!' && _int <= '/') 
	|| (_int >= ':' && _int <= '~'))
	{
		_char = static_cast<char>(_int);
		_statusChar = OK;
	}
	else
		_statusChar = IMPOSSIBLE;
}

TYPE_L ScalarConverter::fType()
{
	size_t i = 0;

	if (!_ptr.compare("-inf") || !_ptr.compare("+inf") || !_ptr.compare("nan"))
		return (DOUBLE);
	if (!_ptr.compare("-inff") || !_ptr.compare("+inff") || !_ptr.compare("nanf"))
		return (FLOAT);
	if (_ptr.size() == 1 && ((_ptr[0] >= '!' && _ptr[0] <= '/') 
	|| (_ptr[0] >= ':' && _ptr[0] <= '~')))
	{
		return (CHAR);
	}
	if (_ptr[i] != '-' && _ptr[i] != '+' && (_ptr[i] < '0' || _ptr[i] > '9'))
	{
		_status = ERROR;
		throw MyException("Syntax ERROR");
	}
	if (_ptr[i] == '-' || _ptr[i] == '+')
		i++;
	if (_ptr[i] < '0' || _ptr[i] > '9')
	{
		_status = ERROR;
		throw MyException("Syntax ERROR");
	}
	for (; i < _ptr.size() && ((_ptr[i] >= '0' && _ptr[i] <= '9')); ++i);
	if ((_ptr[i] == '.' && ((i + 1) == _ptr.size() || _ptr[i + 1] < '0' || 
	_ptr[i + 1] > '9')) || (_ptr[i] == 'f' && (i + 1) != _ptr.size()) || (_ptr[i] != '.' 
	&& _ptr[i] != 'f' && i != _ptr.size()))
	{
		_status = ERROR;
		throw MyException("Syntax ERROR");
	}
	++i;
	for (; i < _ptr.size() && ((_ptr[i] >= '0' || _ptr[i] <= '9') || _ptr[i] == 'f'); ++i)
	{
		if (_ptr[i] == 'f' && (i + 1) != _ptr.size())
		{
			_status = ERROR;
			throw MyException("Syntax ERROR");
		}
		if (_ptr[i] < '0' && _ptr[i] > '9' && _ptr[i] != 'f')
		{
			_status = ERROR;
			throw MyException("Syntax ERROR");
		}
	}
	if (_ptr[_ptr.size() - 1] == 'f')
		return (FLOAT);
	for (size_t i = 0; i < _ptr.size(); i++)
	{
		if (_ptr[i] == '.')
			return (DOUBLE);
	}
	_status = OK;
	return (INT);
}

STATUS ScalarConverter::getStatus()
{
	return (_status);
}

char ScalarConverter::getChar()
{
	return (_char);
}

int ScalarConverter::getInt()
{
	return (_int);
}

float ScalarConverter::getFloat()
{
	return (_float);
}

double ScalarConverter::getDouble()
{
	return (_double);
}

STATUS ScalarConverter::getCharStatus()
{
	return (_statusChar);
}

STATUS ScalarConverter::getIntStatus()
{
	return (_statusInt);
}

STATUS ScalarConverter::getFloatStatus()
{
	return (_statusFloat);
}

STATUS ScalarConverter::getDoubleStatus()
{
	return (_statusDouble);
}

// -------->>  My Exception -------------->>

ScalarConverter::MyException::MyException(const std::string &error) : _error(error) {}

ScalarConverter::MyException::~MyException() throw() {}

const char *ScalarConverter::MyException::what() const throw() { return ((_error.data())); }

// -------->> END  My Exception -------------->>