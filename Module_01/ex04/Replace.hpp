/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:35:13 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:14 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __REPLACE_HPP__
#define __REPLACE_HPP__

#include <iostream>
#include "myFile.hpp"

class Replace
{
private:

	std::string inFile;
	std::string outFile;

public:

	Replace(std::string infile);

	void replace(std::string fiptr , std::string repptr);

	~Replace();
};

#endif