/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:36:19 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:36:20 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>

class Harl
{
private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	void complain(std::string level);
	Harl();
	~Harl();
};

#endif