#include "main.hpp"
#include <iomanip>

int main(int c, char **v)
{
	// std::cout << std::setfill ('x') << std::setw (10) << "7777" << "." << std::endl;
	// std::cout << "a" << std::endl;

	(void)c;
	(void)v;

	// Contact a;
	// a.set_darkest_secret("asdasdasd");
	// a.set_first_name("bs");
	// a.set_last_name("cadasdasd");
	// a.set_nickname("dsdasdasd");
	// a.set_phone_number("esdasdda");
	// std::cout << a;
	// a.print(5);
	std::string lin;
	PhoneBook a;
	while (1)
	{
		std::cout<<"Select one of the following commands"<<std::endl;
        std::cout<<">:ADD    >:SEARCH     >:EXIT"<<std::endl;
		std::cin >> lin;
		if (lin == "ADD")
			a.add();
		else if (lin == "SEARCH")
			a.search();
		else if (lin == "EXIT")
			return (0);
		else if (!lin.size())
			std::cout << std::endl;
		else
			std::cout << "ERROR" << std::endl;
	}

	// std::string b;
	// {
	// 	std::string a("aaaaaaaaa");
	// 	b = a;
	// }
	// std::cout << b << std::endl;
	// PhoneBook b;
	// Contact a2(a);
	// PhoneBook b2(b);
	// (void)a2;
	// (void)b2;
	return (0);
}