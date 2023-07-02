#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact 
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact ();
	Contact (Contact &ptr);

	void set_first_name(std::string ptr);
	void set_last_name(std::string ptr);
	void set_nickname(std::string ptr);
	void set_phone_number(std::string ptr);
	void set_darkest_secret(std::string ptr);

	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();

	void full_print();
	void print(int indexs);

private:

	void	print_stan(std::string ptr);

public:

	~Contact();
};

#endif