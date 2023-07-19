#include "Serializer.hpp"

int main()
{
	Data* a = new Data;

	a->a = 15;
	a->b = 15.0;
	a->c = 15.0f;

	Data* c = Serializer::deserialize(Serializer::serialize(a));

	std::cout << " a * = " << a << "\nc * = " << c << "\n";
	std::cout << "c -> " << c->a << " " << c->b << " " << c->c << "\n";

	return (0);
}