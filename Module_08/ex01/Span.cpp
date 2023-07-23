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
		throw MyException("Error add Number");
	this->_data.push_back(number);
}

int &Span::operator[](unsigned int id)
{
	if (id >= this->_data.size())
		throw MyException("Error indexs");
	return (this->_data.at(id));
}

size_t Span::getSize()
{
	return (this->_data.size());
}

void Span::range(unsigned int begin, unsigned int end, int data)
{
	if (this->_data.capacity() < 1)
		throw MyException("Error Emty");
	if (end > this->_data.capacity() || end < begin)
		throw MyException("Error indexs");
	std::vector<int>::iterator it = this->_data.begin();
	this->_data.insert(it + begin, end - begin, data);
}

int Span::shortestSpan()
{
	int r = 0;

	if (this->_data.size() < 2)
		throw MyException("Error numbers stored, or only one");
	std::vector<int> a(this->_data);
	std::sort(a.begin(), a.end());
	r = std::abs(a[0] - a[1]);
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		if (std::abs(std::abs(a[i] - a[i + 1])) < r)
			r = std::abs(std::abs(a[i] - a[i + 1]));
	}
	return (r);
}

int Span::longestSpan()
{
	if (this->_data.size() < 2)
		throw MyException("Error numbers stored, or only one");
	std::vector<int> a(this->_data);
	std::sort(a.begin(), a.end());
	return (a[a.size() - 1] - a[0]);
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
