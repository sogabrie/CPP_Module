#include "Base.hpp"
#include <typeinfo>

Base * generate(void)
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	switch (localTime->tm_sec % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	default:
		return (new C());
	}
}

void identify(Base* p)
{
	(void)p;
}

void identify(Base& p)
{
	(void)p;
}

int main()
{
	int g;
	(void)g;
	// Base b;
	int t;
	(void)t;
	const std::type_info & a = typeid(Base);
	std::cout << a.name() << std::endl;
	return (0);
}