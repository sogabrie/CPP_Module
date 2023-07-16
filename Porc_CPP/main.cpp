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
        double value = strtod("92233720368547758079999999999999", NULL);
        int a = (int)value;
		//static_cast<int>(value);
        std::cout << value << " a = " << a << "\n";
		// int g = std::stoi("2147483648");
		double g = std::stod("a-nan");
		std::cout << g << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << '\n';
    }
    return (0);
}