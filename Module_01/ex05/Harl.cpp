#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my \n \
	7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put \n \
	 enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for \n \
	years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int		i						=	0;
	int 	lev						=	0;
	void	(Harl::*mas[4])() = {debug,

	if (level.size() != 1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}
	lev = level[0] - 48;
	if (lev > 4 && lev < 1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	} 
	for (; i < lev; i++){};
	this->(*(mas[0]))();
}

Harl::Harl()
{
}

Harl::~Harl()
{
}