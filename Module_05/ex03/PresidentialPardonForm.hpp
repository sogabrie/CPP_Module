#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:

	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void		beSigned(Bureaucrat const & bur);
	bool		execute(Bureaucrat const & executor) const;
};

#endif