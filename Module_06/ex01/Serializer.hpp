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
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);

public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif