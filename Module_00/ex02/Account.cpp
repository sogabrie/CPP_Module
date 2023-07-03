/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:18:07 by sogabrie          #+#    #+#             */
/*   Updated: 2023/07/03 15:18:08 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
	";total:" << _totalAmount << ";deposits:" << \
	_totalNbDeposits << ";withdrawals:" << \
	_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	++_nbAccounts;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount \
	<< ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
	<< this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << 
	";deposit:" << deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	++_totalNbDeposits;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << \
	";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return (0);
	}
	std::cout << withdrawal << ";";
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount \
	<< ";nb_withdrawals:" << this->_nbDeposits << std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";deposits:" << \
	this->_nbDeposits << ";withdrawals:" << \
	this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout <<buffer << " ";
}

Account::Account( void )
{

}