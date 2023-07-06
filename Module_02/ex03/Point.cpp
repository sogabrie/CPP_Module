/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:23:15 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/06 16:23:16 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x1, const float y1): x(x1), y(y1)
{
}

Point::Point(const Point &other):x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
    (Fixed)this->x = other.x;
    (Fixed)this->y = other.y;
    return (*this);
}

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}
