#include "BitcoinExchange.hpp"

int main(int c, char ** v)
{
	if (c != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (0);
	}
	try
	{
		BitcoinExchange a;
		a.btc("data.csv", v[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}