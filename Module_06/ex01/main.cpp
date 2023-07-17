#include "Serializer.hpp"

int main()
{
	Data* a = new Data;
	Serializer b;

	a->a = 15;
	a->b = 15.0;
	a->c = 15.0f;

	Data* c = b.deserialize(b.serialize(a));

	std::cout << " a * = " << a << "\nc * = " << c << "\n";
	std::cout << "c -> " << c->a << " " << c->b << " " << c->c << "\n";

	return (0);
}