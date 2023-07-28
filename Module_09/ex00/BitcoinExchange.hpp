#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, std::string> _data1;
	std::map<std::string, std::string> _data2;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & other);
	BitcoinExchange & operator=(const BitcoinExchange & other);
	~BitcoinExchange();

	void btc(std::string file1, std::string file2);
};

#endif