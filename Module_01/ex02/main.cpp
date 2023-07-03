/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:50:12 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/03 18:50:30 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string a("HI THIS IS BRAIN");
	std::string *stringPTR = &a;
	std::string &stringREF = a;

	std::cout << std::endl << "string address   -> " << &a << std::endl;
	std::cout << "stringPTR        -> " << stringPTR << std::endl;
	std::cout << "stringREF        -> " << &stringREF << std::endl << std::endl;

	std::cout << "string value     -> " << a << std::endl;
	std::cout << "stringPTR  value -> " << *stringPTR << std::endl;
	std::cout << "stringREF value  -> " << stringREF << std::endl << std::endl;
}