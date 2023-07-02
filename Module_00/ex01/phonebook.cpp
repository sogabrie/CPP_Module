#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->first = 0;
	this->last = 0;
}

PhoneBook::PhoneBook(PhoneBook &ptr)
{
	(void)ptr;
}

void	PhoneBook::search()
{
	long double	ptr = 0;

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
		if (std::cin.fail() || (ptr - 1) < 0 || ptr > this->size)
		{
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Error" << std::endl;
			ptr = 0;
		}
	}
	this->mas[(int)ptr - 1].full_print();
}
void	PhoneBook::add()
{
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
}

void	PhoneBook::add_cin(int indexs)
{
	std::string ptr;

	std::getline(std::cin, ptr);
	while (!ptr.size() || ptr[0] == '\n')
	{
		ptr.clear();
		std::cout << "Please set first name: ";
		std::getline(std::cin, ptr);
	}
	this->mas[indexs].set_first_name(ptr);
	ptr.clear();
	while (!ptr.size() || ptr[0] == '\n')
	{
		ptr.clear();
		std::cout << "Please set last name: ";
		std::getline(std::cin, ptr);
	}
	this->mas[indexs].set_last_name(ptr);
	ptr.clear();
	while (!ptr.size() || ptr[0] == '\n')
	{
		ptr.clear();
		std::cout << "Please set nicknamee: ";
		std::getline(std::cin, ptr);
	}
	this->mas[indexs].set_nickname(ptr);
	ptr.clear();
	while (!ptr.size() || ptr[0] == '\n')
	{
		ptr.clear();
		std::cout << "Please set phone number: ";
		std::getline(std::cin, ptr);
		for (size_t i = 0; i < ptr.size(); i++)
		{
			if (ptr[i] < 48 || ptr[i] > 57)
				ptr.clear();
		}
	}
	this->mas[indexs].set_phone_number(ptr);
	ptr.clear();
	while (!ptr.size() || ptr[0] == '\n')
	{
		ptr.clear();
		std::cout << "Please set darkest secret: ";
		std::getline(std::cin, ptr);
	}
	this->mas[indexs].set_darkest_secret(ptr);
}

PhoneBook::~PhoneBook()
{

}