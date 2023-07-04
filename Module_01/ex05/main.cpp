/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:35:46 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:47 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int c, char **v)
{
	Harl a;
	std::string s[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (c != 2)
	{
		std::cout << "ERROR argumen count" << std::endl;
		return (1);
	}
	if (s[0].compare(v[1]) && s[1].compare(v[1]) && s[2].compare(v[1]) && s[3].compare(v[1]))
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (2);
	}
	a.complain(v[1]);
	return (0);
}