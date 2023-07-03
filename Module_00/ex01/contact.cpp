/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:19:13 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/03 15:19:14 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(Contact &ptr)
{
	this->first_name = ptr.first_name;
	this->darkest_secret = ptr.darkest_secret;
	this->last_name = ptr.last_name;
	this->nickname = ptr.nickname;
	this->phone_number = ptr.phone_number;
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

void Contact::full_print()
{
	std::cout << "First Name     -> " << this->first_name << std::endl;
	std::cout << "last_name      -> " << this->last_name << std::endl;
	std::cout << "nickname       -> " << this->nickname << std::endl;
	std::cout << "phone_number   -> " << this->phone_number << std::endl;
	std::cout << "darkest_secret -> " << this->darkest_secret << std::endl;
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
		std::cout << ptr.substr(0,9);
		std::cout << '.';
	}
}

Contact::~Contact()
{
}