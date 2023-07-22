#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int> _data;
	Span();
public:
	Span(unsigned int size);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	int & operator[](unsigned int id);
	size_t getSize();

	int	shortestSpan();
	int	longestSpan();

private:
	class MyException : public std::exception
	{
	private:
		const std::string _error;
	public:
		MyException(const std::string& error);
		~MyException() throw();
		const char * what () const throw ();
	};
};

std::ostream& operator<<(std::ostream& o, Span& mas);

#endif