#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->first = 0;
	this->last = 0;
	// std::cout << "PhoneBook constructor" << std::endl;
}

PhoneBook::PhoneBook(PhoneBook &ptr)
{
	(void)ptr;
	// std::cout << "PhoneBook copy" << std::endl;
}

void	PhoneBook::search()
{
	long double	ptr = 0;

	// std::cout << "1_first  = " << this->first << std::endl;
	// std::cout << "1_lasst  = " << this->last << std::endl;
	if (this->size == 0)
	{
		std::cout << "Phone Book empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < this->size ; i++)
	{
		this->mas[i].print(i + 1);
	}
	while (!ptr)
	{
		std::cout << "Please, enter indexs: ";
		std::cin >> std::get_money(ptr);
		if (std::cin.fail() || !(ptr - 1) || ptr > this->size)
		{
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Error" << std::endl;
			ptr = 0;
		}
	}
	std::cout << this->mas[(int)ptr];
}
void	PhoneBook::add()
{
	std::cout << "0_size  = " << this->size << std::endl;
	if (this->size < 10)
	{
		add_cin(this->size);
		++this->size;
	}
	else
	{
		for (size_t i = 0; i < 9; i++)
			this->mas[i] = this->mas[i + 1];
		add_cin(9);
	}
	std::cout << "0_size  = " << this->size << std::endl;
}

void	PhoneBook::add_cin(int indexs)
{
	std::string ptr;

	if (!ptr.size())
	{
		std::cout << "Please set first name: ";
		std::cin >> ptr;
	}
	this->mas[indexs].set_first_name(ptr);
	ptr.clear();
	if (!ptr.size())
	{
		std::cout << "Please set last name: ";
		std::cin >> ptr;
	}
	this->mas[indexs].set_last_name(ptr);
	ptr.clear();
	if (!ptr.size())
	{
		std::cout << "Please set nicknamee: ";
		std::cin >> ptr;
	}
	this->mas[indexs].set_nickname(ptr);
	ptr.clear();
	if (!ptr.size())
	{
		std::cout << "Please set phone number: ";
		std::cin >> ptr;
	}
	this->mas[indexs].set_phone_number(ptr);
	ptr.clear();
	if (!ptr.size())
	{
		std::cout << "Please set darkest secret: ";
		std::cin >> ptr;
	}
	this->mas[indexs].set_darkest_secret(ptr);
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBook distructor" << std::endl;
}