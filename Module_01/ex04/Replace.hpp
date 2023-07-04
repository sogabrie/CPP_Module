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