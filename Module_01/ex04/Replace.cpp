/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:35:09 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:10 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string infile):inFile(infile)
{
	this->outFile = this->inFile + ".replace";
}

void Replace::replace(std::string fiptr , std::string repptr)
{
	size_t 		pos;
	std::string str;
	
	myFile::get_cin(this->inFile, str);
	pos = str.find(fiptr);
	while ( pos != std::string::npos ) 
	{
		str.erase(pos, fiptr.length());
		str.insert(pos, repptr);
		pos = str.find(fiptr);
	}
	myFile::set_out(this->outFile, str);
}

Replace::~Replace()
{
}