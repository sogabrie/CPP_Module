#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "Bureaucrat.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:

public:

	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();


	void		beSigned(Bureaucrat const & bur);
	bool		execute(Bureaucrat const & executor) const;
};

#endif