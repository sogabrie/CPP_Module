#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:

	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();


	void		beSigned(Bureaucrat & bur);
	void		execute(Bureaucrat const & executor) const;
};

#endif