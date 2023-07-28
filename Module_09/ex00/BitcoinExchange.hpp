#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <algorithm>
#include <iostream>
#include <fstream>
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

private:
	void openfile(std::string file1);

	class MyException : public std::exception
	{
	private:
		const std::string _error;
	public:
		MyException(const std::string& error);
		~MyException() throw();
		const char * what () const throw ();
	};
};

#endif