/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 14:23:10 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// constructor and destructor

Harl::Harl(void) {}

Harl::~Harl() {}

// private member functions

void	Harl::debug(void)
{
	std::string msg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");

	std::cout << msg << std::endl;
}

void	Harl::info(void)
{
	std::string		msg("I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!");

	std::cout << msg << std::endl;
}

void	Harl::warning(void)
{
	std::string		msg("I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.");

	std::cout << msg << std::endl;
}

void	Harl::error(void)
{
	std::string		msg("This is unacceptable! I want to speak to the manager now.");

	std::cout << msg << std::endl;
}

//public member function

void	Harl::complain(std::string level)
{
	std::string	options[4] =
	{
		"DEBUG",
		"WARNING",
		"INFO",
		"ERROR"
	};
	void (Harl::*f[4])(void) = {
		&Harl::debug,
		&Harl::warning,
		&Harl::info,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (options[i].compare(level) == 0)
			(this->*f[i])();
	}
}
