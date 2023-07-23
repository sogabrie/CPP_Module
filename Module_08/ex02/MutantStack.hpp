#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack();
	~MutantStack();
	
};

template <typename T>
MutantStack<T>::MutantStack()
{
	this->c
}
template <typename T>
MutantStack<T>::~MutantStack()
{}


#endif