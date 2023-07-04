/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:36:23 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:36:24 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "ERROR argumen count" << std::endl;
		return (2);
	}
	Harl a;
	a.complain(v[1]);
	return (0);
}