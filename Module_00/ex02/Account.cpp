#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::getNbAccounts( void )
{

}

int	Account::getTotalAmount( void )
{

}

int	Account::getNbDeposits( void )
{

}

int	Account::getNbWithdrawals( void )
{

}

void	Account::displayAccountsInfos( void )
{

}

Account::Account( int initial_deposit )
{

}

Account::~Account( void )
{

}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{
	return (0);
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "[%Y%m%d%H%M%S]", localTime);
	std::cout <<buffer << " ";
}

Account::Account( void )
{

}