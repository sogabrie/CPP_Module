/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:47 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:33:48 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:

	std::string name;
	Weapon *weap;

public:

	HumanA(std::string name, Weapon &weap);
	~HumanA();

	void attack();
};

#endif