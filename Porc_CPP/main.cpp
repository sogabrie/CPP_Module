#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <stdlib.h>
#include <iomanip> 
#include <float.h>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>


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
	// std::vector<int> a {1,2,3,4,5,6,};
	std::vector<int> a(15,0);

	// a.push_back(10);
	// a.resize(5,100);	
	// a.reserve(100);
	// a.shrink_to_fit();
	// a.assign(15, 100);
	// std::vector<int>::iterator it = a.begin();
	// a.insert((it) ,3, 500);
	// std::cout << "size = " << a.size() << "\n";
	// std::cout << "max_size = " << a.max_size() << "\n";
	// std::cout << "capasiti = " << a.capacity() << "\n";
	// try
	// {
	// 	std::cout << "-- " << a.at(5) << "\n";
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	for (size_t i = 0; i < a.size(); i++)
	{
		// std::cout << a[i] << " ";
		std::cout << a.data()[i] << " ";
	}
	std::cout << std::endl;
	

	// double a = 6;
	// std::cout.precision(a);
	// std::cout << std::to_string(a) << std::endl;

    // try
    // {
    //     // double value = strtod("99999.9999", NULL);
    //     // int a = (int)value;
	// 	// // static_cast<int>(value);
    //     // std::cout << value << " a = " << a << "\n";
	// 	// int g = std::stoi("2147483648");
	// 	// float g = std::stof("");
    //     // int a = static_cast<int>(g);
	// 	// std::cout << g << "   " << a << "\n";

	// 	const int a = 12;

	// 	std::cout << "a = " <<  a  << "\n";

	// 	// bbb(a);
	// 	const_cast<int>(a) =  a + a;

	// 	std::cout << "a = " <<  a  << "\n";
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "ERROR " << e.what() << '\n';
    // }
    return (0);
}