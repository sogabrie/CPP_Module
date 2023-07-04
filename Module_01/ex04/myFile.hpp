/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myFile.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:35:05 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:06 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MYFILE_HPP__
#define __MYFILE_HPP__

#include <iostream>
#include <fstream>

class myFile
{
public:
	static int get_cin(std::string filename, std::string &ptr);
	static int set_out(std::string filename, std::string &ptr);
private:
	myFile();
	~myFile();
};

#endif