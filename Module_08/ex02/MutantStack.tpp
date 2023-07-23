#pragma once 
#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

template <class T, class VE>
MutantStack<T,VE>::MutantStack()
{
}
template <class T, class VE >
MutantStack<T, VE>::~MutantStack()
{

}

template <class T, class VE >
MutantStack<T, VE>::MutantStack( const MutantStack& other )
{ 
	*this = other; 
}

template <class T, class VE >
MutantStack<T, VE>&    MutantStack<T, VE>::operator=( const MutantStack& other ) 
{
	std::stack< T, VE >::operator=( other );
	return *this;
}

template <class T, class VE >
typename VE::iterator   MutantStack<T, VE >::begin()
{
	return this->c.begin();
}

template <class T, class VE >
typename VE::iterator    MutantStack<T,  VE >::end()
{
	return this->c.end();
}

#endif