#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>

struct Data
{
	int		a;
	float	c;
	double	b;
};

class Serializer
{
private:
public:
	Serializer();
	~Serializer();

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};
#endif