#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int size) : _data(0, 0)
{
	this->_data.reserve(size);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if(this != &other)
		this->_data = other._data;
	return (*this); 
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (this->_data.size() == this->_data.capacity())
		throw MyException("Error add Number\n");
	this->_data.push_back(number);
}

int &Span::operator[](unsigned int id)
{
	if (id >= this->_data.size())
		throw MyException("Error indexs\n");
	return (this->_data.at(id));
}

size_t Span::getSize()
{
	return (this->_data.size());
}

int Span::shortestSpan()
{
	if (this->_data.size() < 2)
		throw MyException("Error numbers stored, or only one");
	return 0;
}

int Span::longestSpan()
{
	return 0;
}

// -------->>  My Exception -------------->>

Span::MyException::MyException(const std::string &error) : _error(error) {}

Span::MyException::~MyException() throw() {}

const char *Span::MyException::what() const throw() { return ((this->_error.data())); }

std::ostream &operator<<(std::ostream &o, Span& mas)
{
	for (size_t i = 0; i < mas.getSize(); i++)
	{
		o << mas[i] << " "; 
	}
	o << "\n";
	return (o);
}
