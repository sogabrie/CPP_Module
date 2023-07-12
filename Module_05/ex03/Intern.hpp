#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(const Intern & other);
	Intern & operator=(const Intern & other);
	~Intern();

	AForm* makeForm(std::string const & fr, std::string const & name);
};

#endif