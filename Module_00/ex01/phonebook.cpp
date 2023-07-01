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
	size_t i = 0;

	// std::cout << "1_first  = " << this->first << std::endl;
	// std::cout << "1_lasst  = " << this->last << std::endl;
	if (this->size == 0)
	{
		std::cout << "Phone Book empty" << std::endl;
	}
	for (; (this->first + i) % 10 != this->last; i++)
	{
		// std::cout << "i = " << i << std::endl;
		this->mas[this->first + i].print(i + 1);
	}
	this->mas[this->last].print(i + 1); 
	while (!ptr)
	{
		std::cout << "Please, enter indexs: ";
		std::cin.tie();
		std::cin >> std::get_money(ptr);
		if (std::cin.fail() || !(ptr - 1) || ((this->first + ((int)ptr - 1)) % 10) >  ((this->last + ((int)ptr - 1)) % 10) || ptr > this->size)
		{
			std::cout << "Error" << std::endl;
			ptr = 0;
		}
	}
	std::cout << this->mas[((this->first + ((int)ptr - 1)) % 10)];
}
void	PhoneBook::add()
{
	int	t;

	std::cout << "0_first  = " << this->first << std::endl;
	std::cout << "0_lasst  = " << this->last << std::endl;
	std::cout << "0_size  = " << this->size << std::endl;
	if (this->size < 1)
	{
		add_cin(0);
		++this->size;
		return ;
	}
	if (this->size == 1)
	{
		add_cin(1);
		++this->size;
		this->last = 1;
		return ;
	}
	t = (this->last + 11) % 10;
	if (t == (int)this->first)
	{
		// std::cout << "aaaaaa_0\n";
		this->last = this->first;
		this->first =  (this->first + 11) % 10;
		add_cin(this->last);
	}
	else
	{
		// std::cout << "aaaaaa_1\n";
		++(this->size);
		++(this->last);
		add_cin(this->last);
	}
	std::cout << "0_first  = " << this->first << std::endl;
	std::cout << "0_lasst  = " << this->last << std::endl;
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