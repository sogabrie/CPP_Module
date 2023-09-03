#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>

class RPN
{
private:

	std::stack<double> _my_stack;

public:

	RPN();
	RPN(const RPN & other);
	RPN & operator=(RPN const & other);
	~RPN();

	void rpn(std::string a);

private:

	void	Add();
	void	Subtract();
	void	Multiple();
	void	Devide();

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

#endif