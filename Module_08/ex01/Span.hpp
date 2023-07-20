#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int> _data;
public:
	Span(unsigned int size);
	~Span();
};

#endif