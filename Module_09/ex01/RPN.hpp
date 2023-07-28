#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>

class RPN
{
private:

	typedef enum s_TYPE
	{
	}		TYPE;

	typedef struct s_type
	{
		TYPE _type;
		double number;
	}	t_type;

	std::stack<t_type> _my_stack;

public:

	RPN();
	~RPN();
};

#endif