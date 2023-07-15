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
        double value = strtod("aaa", NULL);
        int a = atoi("u");
        std::cout << value << " "<< a << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << '\n';
    }
    return (0);
}