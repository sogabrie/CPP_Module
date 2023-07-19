#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template<class T>
class Array
{
private:
	unsigned int	_size;
	T 				*_mas;
public:
	Array();
	Array(unsigned int size);
	Array(const Array& other);
	Array<T>& operator=(const Array& other);
	T& operator[](unsigned int it);
	unsigned int size() const;
	~Array();
};

#include "Array.tpp"
#endif
