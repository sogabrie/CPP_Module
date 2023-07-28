#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::btc(std::string file1, std::string file2)
{
	openfile(file1, file2);
}

void BitcoinExchange::openfile(std::string file1, std::string file2)
{
	std::ifstream myfile(file1);
	std::string ptr;
	std::string ptr2;
	std::string ptr3;
	if (myfile.is_open())
	{
		while(std::getline(myfile, ptr))
		{
			size_t pos = ptr.find(",");
			this->_data1.insert(std::pair<std::string, std::string>( ptr3.assign(ptr,0,pos), ptr2.assign(ptr,pos + 1 , ptr.size() - (pos + 1))));
		}
	}
	else
	{
		myfile.close();
		throw MyException("ERROR Open file " + file1 + "\n");
	}
	for (std::map<std::string, std::string>::iterator it = this->_data1.begin(); it != this->_data1.end() ; it++)
	{
		std::cout << it->first << "--" << it->second << "\n";
	}
	
	std::ifstream myfile2(file2);
	if (myfile2.is_open())
	{
		while(std::getline(myfile2, ptr))
		{
			std::cout << ptr << std::endl;
		}
	}
	else
	{
		myfile2.close();
		throw MyException("ERROR Open file " + file2 + "\n");
	}
	myfile2.close();
}

// -------->>  My Exception -------------->>

BitcoinExchange::MyException::MyException(const std::string &error) : _error(error) {}

BitcoinExchange::MyException::~MyException() throw() {}

const char *BitcoinExchange::MyException::what() const throw() { return ((this->_error.data())); }
