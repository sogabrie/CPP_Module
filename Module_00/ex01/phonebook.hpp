#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "contact.hpp"

class PhoneBook
{
private:
	Contact mas[10];
	size_t	size;
	size_t	first;
	size_t	last;
public:
	PhoneBook ();
	PhoneBook (PhoneBook &ptr);

	void	add();
	void	search();

private:

	void	add_cin(int indexs);

public:
	~PhoneBook();
};

#endif