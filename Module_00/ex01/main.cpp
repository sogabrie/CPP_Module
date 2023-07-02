#include "main.hpp"
#include <iomanip>

int main()
{
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
	return (0);
}