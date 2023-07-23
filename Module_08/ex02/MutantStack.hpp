#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>

template <class T, class VE = std::deque< T > >
class MutantStack : public std::stack<T, VE>
{
private:

public:
	MutantStack();
	~MutantStack();

    MutantStack( const MutantStack& other );
    MutantStack&    operator=( const MutantStack& other );
	
	typedef typename VE::iterator    iterator;

    iterator    begin();
    iterator    end();
	
};

#include "MutantStack.tpp"
#endif