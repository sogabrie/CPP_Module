/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:17:59 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/15 15:59:07 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int size = 10;

	Zombie *a = zombieHorde(size, "zombieHorde");
	for (int i = 0; i < size; i++)
		a[i].announce();
	delete[] a;
	return (0);
}