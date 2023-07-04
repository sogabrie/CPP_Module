/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:57 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:33:58 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:

	std::string name;
	Weapon *weap;

public:

	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &wear);
	void attack();
};

#endif