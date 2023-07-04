#include "myFile.hpp"

int myFile::get_cin(std::string filename, std::string &ptr)
{
	std::ifstream myfile(filename);
	if (myfile.is_open())
	{
		if (!std::getline(myfile, ptr, '\0'))
		{
			std::cout << "Empty file" << std::endl;
			myfile.close();
			exit(1);
		}

	}
	else
	{
		std::cout << "ERROR file "<< filename << std::endl;
		myfile.close();
		exit(1);
	}
	myfile.close();
	return (0);
}

int myFile::set_out(std::string filename, std::string &ptr)
{
	std::ofstream myfile(filename);
	if (myfile.is_open())
	{
		myfile << ptr;
	}
	else
	{
		std::cout << "ERROR file "<< filename << std::endl;
		myfile.close();
		exit(1);
	}
	myfile.close();
	return (0);
}

myFile::myFile()
{
}

myFile::~myFile()
{
}