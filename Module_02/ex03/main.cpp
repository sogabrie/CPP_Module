#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
    if (bsp(Point(7, 7), Point(11, 1), Point(2, 2), Point(2.1, 2.1))) 
	{
        std::cout << "mechna" << std::endl;
    } 
	else 
	{
        std::cout << "dursna" << std::endl;
    }
    return 0;
}