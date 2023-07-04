/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:43 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:33:44 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap)
{
	this->name = name;
	this->weap = &weap;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weap)
		std::cout << *(this->weap->getType());
	std::cout << std::endl;
}