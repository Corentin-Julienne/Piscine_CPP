/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:38:53 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 12:31:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"

Timer::Timer(void) : _start(-1), _stop(-1) {}

Timer::~Timer() {}

Timer::Timer(const Timer& other) : _start(other._start), _stop(other._stop) {}

Timer&	Timer::operator=(const Timer& other)
{
	if (this != &other)
	{
		_start = other._start;
		_stop = other._stop;
	}
	return *this;
}

void	Timer::clockStart(void)
{
	if (this->_start == (-1))
		this->_start = this->_getTimeNow();
	else
		std::cerr << "Reset the current clock before starting it" << std::endl;
}

void	Timer::clockStopper(void)
{
	if (this->_stop == (-1))
		this->_stop = this->_getTimeNow();
	else
		std::cerr << "Start a clock before trying to starting it" << std::endl;
}

void	Timer::clockReset(void)
{
	this->_start = -1;
	this->_stop = -1;
}

void	Timer::printTaskDuration(void)
{
	long long		duration = _stop - _start;
	
	std::cout << " : " << duration << " microseconds" << std::endl;
}

/* get the current time in milliseconds (0 = Linux Epoch) */
long long	Timer::_getTimeNow(void)
{
	struct timeval		timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000000) + (timestamp.tv_usec));
}
