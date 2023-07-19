#pragma once
#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <iostream>

template <typename T>
Array<T>::Array(): _size(0), _mas(new T()) {}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	this->_mas = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
	this->_mas = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_mas[i] = other._mas[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_mas;
		this->_size = other._size;
		this->_mas = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_mas[i] = other._mas[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int it)
{
	if (it >= 0 && it < this->_size)
		return (this->_mas[it]);
	throw std::exception();
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_mas;
}

#endif