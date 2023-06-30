#include <iostream>

std::string form(std::string ptr)
{
    for (size_t i = 0; i < ptr.size(); i++)
    {
        if (ptr[i] > '`' && ptr[i] < '{')
            ptr[i] = ptr[i] - 32;
    }
    return (ptr);
}

int main(int c, char **v)
{
    if (c < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        --c;
        ++v;
        for (int i = 0; i < c; i++)
            std::cout << form(v[i]);
        
    }
    std::cout << std::endl;
    return (0);
}