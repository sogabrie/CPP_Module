/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:21:46 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/03 15:21:48 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "contact.hpp"

class PhoneBook
{
private:

	Contact mas[10];
	size_t	size;
	size_t	first;
	size_t	last;

public:

	PhoneBook ();
	PhoneBook (PhoneBook &ptr);

	void	add();
	void	search();

private:

	void	add_cin(int indexs);

public:
	~PhoneBook();
};

#endif