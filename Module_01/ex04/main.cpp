/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:34:52 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:34:53 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

int main (int c, char **v) 
{
	if (c != 4)
	{
		std::cout << "ERROR argument" << std::endl;
		return (1);
	}
	Replace a(v[1]);
	a.replace(v[2], v[3]);
	return 0;
}