/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:23:23 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/06 16:23:24 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
private:

    const Fixed x;
    const Fixed y;

public:
    Point();
    Point( const float x1, const float y1);
    Point( const Point &other);
    ~Point();

    Point&  operator=( const Point &other);

    Fixed getX() const ;
    Fixed getY() const ;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif