#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
		*this = other;
	return(*this);
}

RPN::~RPN()
{
}

void RPN::rpn(std::string a)
{
	if (!a.size())
		throw MyException("Empty list\n");
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a.at(i) >= 48 && a.at(i) <= 57)
			this->_my_stack.push(static_cast<int>(a.at(i) - 48));
		else if (a.at(i) == '+' || a.at(i) == '-' || a.at(i) == '*' || a.at(i) == '/')
		{
			if (this->_my_stack.size() < 2)
				throw MyException("Syntexs Error\n");
			if(a.at(i) == '+')
				this->Add();
			else if(a.at(i) == '-')
				this->Subtract();
			else if(a.at(i) == '*')
				this->Multiple();
			else
				this->Devide();
		}
		else if (a.at(i) == ' ');
		else
			throw MyException("Error\n");
	}
	if (this->_my_stack.size() != 1)
		throw MyException("Syntexs Error\n");
	else
		std::cout << this->_my_stack.top() << "\n";
}

void RPN::Add()
{
	double a = this->_my_stack.top();
	this->_my_stack.pop();
	a = this->_my_stack.top() + a;
	this->_my_stack.pop();
	this->_my_stack.push(a);
}

void RPN::Subtract()
{
	double a = this->_my_stack.top();
	this->_my_stack.pop();
	a = this->_my_stack.top() - a;
	this->_my_stack.pop();
	this->_my_stack.push(a);
}

void RPN::Multiple()
{
	double a = this->_my_stack.top();
	this->_my_stack.pop();
	a = this->_my_stack.top() * a;
	this->_my_stack.pop();
	this->_my_stack.push(a);
}

void RPN::Devide()
{
	double a = this->_my_stack.top();
	this->_my_stack.pop();
	if (!a)
		throw MyException("Error Devide zero\n");
	a = this->_my_stack.top() / a;
	this->_my_stack.pop();
	this->_my_stack.push(a);
}

// -------->>  My Exception -------------->>

RPN::MyException::MyException(const std::string &error) : _error(error) {}

RPN::MyException::~MyException() throw() {}

const char *RPN::MyException::what() const throw() { return ((this->_error.data())); }