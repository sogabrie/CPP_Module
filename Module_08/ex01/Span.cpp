#include "Span.hpp"

Span::Span(unsigned int size) : _data(0, 0)
{
	this->_data.reserve(size);
}

Span::~Span()
{
}