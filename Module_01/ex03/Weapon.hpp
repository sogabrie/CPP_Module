/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:34:10 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:34:22 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon
{
private:

	std::string *type;

public:

	Weapon();
	Weapon(const std::string type);
	Weapon(const char* type);
	Weapon(const Weapon &weap);
	Weapon& operator=(const Weapon& other);
	~Weapon();

	const std::string* getType();
	void setType(std::string type);

};

#endif