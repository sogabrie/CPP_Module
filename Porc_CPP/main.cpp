#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <stdlib.h>
#include <iomanip> 
#include <float.h>

int main()
{
    try
    {
        double value = strtod("99999.9999", NULL);
        int a = (int)value;
		// static_cast<int>(value);
        std::cout << value << " a = " << a << "\n";
		// int g = std::stoi("2147483648");
		// float g = std::stof("");
        // int a = static_cast<int>(g);
		// std::cout << g << "   " << a << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << '\n';
    }
    return (0);
}