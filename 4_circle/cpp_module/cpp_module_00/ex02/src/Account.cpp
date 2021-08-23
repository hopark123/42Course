#include "Account.hpp"
#include <time.h>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<<";amount:" << _amount \
		<<";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
	return ;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts \
		<< ";total:" << _totalAmount \
		<< ";deposits:" << _totalNbDeposits \
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount\
		<< ";nb_deposits:" << ++_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		std::cout << withdrawal \
			<< ";amount:" << _amount \
			<< ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
		<< ";amount:" << _amount << std::endl;
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";deposits:" << _nbDeposits \
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*now_info;
	char		buffer[20];

	time(&now);
	now_info = localtime(&now);
	strftime( buffer, 20, "[%Y%m%d_%H%M%S] ", now_info );
	std::cout << buffer;
}