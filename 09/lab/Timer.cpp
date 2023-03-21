/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:38:53 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/19 12:00:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"

Timer::Timer(std::string clockName)
{
	start = std::chrono::high_resolution_clock::now();
	this->_clockName = clockName;
}

Timer::~Timer()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	
	float ms = duration.count() * 1000.0f;
	std::cout << this->_clockName << " : Task took " << ms << " milliseonds to complete" << std::endl;	
}
