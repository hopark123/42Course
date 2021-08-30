#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// void	(Karen::*fp[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	int i = 0;
	while(i < 4 && level != arr[i])
		i++;
	switch(i)
	{
		case 0:
			std::cout << "[ debug ]" << std::endl;
			debug();
			std::cout << std::endl;
			break ;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			info();
			std::cout << std::endl;
			break ;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
			std::cout << std::endl;
			break ;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			std::cout << std::endl;
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}