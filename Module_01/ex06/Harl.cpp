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

void Harl::complain(const std::string const level)
{

	switch (level)
	{
	case const std::string("WARNING"):
		/* code */
		break;
	case /* constant-expression */:
		/* code */
		break;
	case /* constant-expression */:
		/* code */
		break;
	case /* constant-expression */:
		/* code */
		break;
	
	default:
		break;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}