#include "contact.hpp"

Contact::Contact()
{
	// std::cout << "Contact constructor" << std::endl;
}

Contact::Contact(Contact &ptr)
{
	this->first_name = ptr.first_name;
	this->darkest_secret = ptr.darkest_secret;
	this->last_name = ptr.last_name;
	this->nickname = ptr.nickname;
	this->phone_number = ptr.phone_number;
	// std::cout << "Contact copy" << std::endl;
}

void Contact::set_first_name(std::string ptr)
{
	this->first_name = ptr;
}
void Contact::set_last_name(std::string ptr)
{
	this->last_name = ptr;
}
void Contact::set_nickname(std::string ptr)
{
	this->nickname = ptr;
}
void Contact::set_phone_number(std::string ptr)
{
	this->phone_number = ptr;
}
void Contact::set_darkest_secret(std::string ptr)
{
	this->darkest_secret = ptr;
}

std::string Contact::get_first_name()
{
	return (this->first_name);
}
std::string Contact::get_last_name()
{
	return (this->last_name);
}
std::string Contact::get_nickname()
{
	return (this->nickname);
}
std::string Contact::get_phone_number()
{
	return (this->phone_number);
}
std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

std::ostream&	operator<<(std::ostream& os, const Contact& dt)
{
	os << "First Name     -> " << dt.first_name << std::endl;
	os << "last_name      -> " << dt.last_name << std::endl;
	os << "nickname       -> " << dt.nickname << std::endl;
	os << "phone_number   -> " << dt.phone_number << std::endl;
	os << "darkest_secret -> " << dt.darkest_secret << std::endl;
	return os;
}

void	Contact::print(int indexs)
{
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10) << indexs;
	std::cout << "|";
	print_stan(this->first_name);
	std::cout << "|";
	print_stan(this->last_name);
	std::cout << "|";
	print_stan(this->nickname);
	std::cout << "|" << std::endl;
}

void	Contact::print_stan(std::string ptr)
{
	if (ptr.size() < 10)
	{
		std::cout << std::setfill (' ') << std::setw (10) << ptr;
	}
	else
	{
		for (size_t i = 0; i < 9; i++)
		{
			std::cout << ptr[i];
		}
		std::cout << '.';
	}
}

Contact::~Contact()
{
	// std::cout << "Contact distructor" << std::endl;
}