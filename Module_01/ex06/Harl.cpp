/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:36:08 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:36:09 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n \
love having extra bacon for my \n \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "[ INFO ]\n \
I cannot believe adding extra bacon costs more money. You didnt put \n \
 enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ]\n \
I think I deserve to have some extra bacon for free. Ive been coming for \n \
years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]\n \
This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string const level)
{
	std::string a[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	for ( ;level != a[i] && i < 5; i++);
	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}

}

Harl::Harl()
{
}

Harl::~Harl()
{
}