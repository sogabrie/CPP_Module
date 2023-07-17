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
	case 2:
		return (new C());
	default:
		return (new Base());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p = A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "p = B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "p = C\n";
	else
		std::cout << "NO type ))\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "p = A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "p = B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "p = C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "NO type ))\n";
			}
			
		}
		
	}
	
}

int main()
{
	Base* a = generate();
	identify(a);
	identify(*a);
	
	delete a;
	return (0);
}