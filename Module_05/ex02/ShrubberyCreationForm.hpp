#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:

public:

	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	void		beSigned(Bureaucrat & bur);
	bool		execute(Bureaucrat const & executor) const;
};

#endif