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
	std::ifstream myfile(file2);
	std::string ptr;
	std::string ptr2;
	size_t pos;
	double value;

	openfile(file1);
	if (myfile.is_open())
	{
		std::getline(myfile, ptr);
		while(std::getline(myfile, ptr))
		{
			pos = ptr.find("|");
			if (pos == std::string::npos)
				std::cout << "Error: bad input => " << ptr << std::endl;
			else
			{
				try
				{
					value = stod(ptr2.assign(ptr, pos + 1 , ptr.size() - (pos + 1)));
				}
				catch(...)
				{
					std::cout << "Error: bad value => " << ptr << std::endl;
					continue;
				}
				if(value < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (value > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
				{
					try
					{
						value *= stod(this->_data1.at(ptr2.assign(ptr,0,pos)));
					}
					catch(...)
					{
						std::map<std::string, std::string>::iterator it, it2;
						for (it = it2 = this->_data1.begin(); it != this->_data1.end(); it2 = it++)
						{
							if (ptr2.assign(ptr,0,pos) < it->first)
							{
								value *= stod(it2->second);
								break;
							}
						}
						if (it == this->_data1.end())
							value *= stod(it2->second);
					}
					std::cout << ptr2.assign(ptr,0,pos) << " => " << ptr2.assign(ptr, pos + 1 , ptr.size() - (pos + 1)) << " = " << value << std::endl;
					
				}
			}
		}
	}
	else
	{
		myfile.close();
		throw MyException("ERROR Open file " + file2 + "\n");
	}
}

void BitcoinExchange::openfile(std::string file1)
{
	std::ifstream myfile(file1);
	size_t pos;
	std::string ptr;
	std::string ptr2;
	std::string ptr3;
	if (myfile.is_open())
	{
		while(std::getline(myfile, ptr))
		{
			pos = ptr.find(",");
			this->_data1.insert(std::pair<std::string, std::string>( ptr3.assign(ptr,0,pos), 
			ptr2.assign(ptr,pos + 1 , ptr.size() - (pos + 1))));
		}
	}
	else
	{
		myfile.close();
		throw MyException("ERROR Open file " + file1 + "\n");
	}
	// for (std::map<std::string, std::string>::iterator it = this->_data1.begin(); it != this->_data1.end() ; it++)
	// {
	// 	std::cout << it->first << "--" << it->second << "\n";
	// }
}

// -------->>  My Exception -------------->>

BitcoinExchange::MyException::MyException(const std::string &error) : _error(error) {}

BitcoinExchange::MyException::~MyException() throw() {}

const char *BitcoinExchange::MyException::what() const throw() { return ((this->_error.data())); }
