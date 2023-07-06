/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:23:00 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/06 16:23:01 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
    if (bsp(Point(7, 7), Point(11, 1), Point(2, 2), Point(2.1, 2))) 
	{
        std::cout << "The point is inside " << std::endl;
    } 
	else 
	{
        std::cout << "the point is not inside the triangle" << std::endl;
    }
    return 0;
}