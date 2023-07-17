#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <stdlib.h>
#include <iomanip> 
#include <float.h>

void aaa(const int &a)
{
	const_cast<int&>(a) =  a + a;
}

void bbb(const int &a)
{
	int &b = const_cast<int&>(a);
	b = 20;
}

int main()
{
    try
    {
        // double value = strtod("99999.9999", NULL);
        // int a = (int)value;
		// // static_cast<int>(value);
        // std::cout << value << " a = " << a << "\n";
		// int g = std::stoi("2147483648");
		// float g = std::stof("");
        // int a = static_cast<int>(g);
		// std::cout << g << "   " << a << "\n";

		const int a = 12;

		std::cout << "a = " <<  a  << "\n";

		// bbb(a);
		const_cast<int>(a) =  a + a;

		std::cout << "a = " <<  a  << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << '\n';
    }
    return (0);
}