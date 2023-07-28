#include "BitcoinExchange.hpp"

int main(int c, char ** v)
{
	(void)v;
	(void)c;
	BitcoinExchange a;
	a.btc("data.csv","input.txt");
	return (0);
}