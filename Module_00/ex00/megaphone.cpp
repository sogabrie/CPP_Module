#include <iostream>

int main(int c, char **v)
{
    if (c < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        std::cout << v[1] << std::endl;
    }
    return (0);
}