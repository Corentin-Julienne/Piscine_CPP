/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:38:55 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 16:40:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
# define TIMER_HPP

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include "PmergeMe.hpp"
#include "FJMI.hpp"

class PmergeMe;
class FJMI;

class Timer
{
	public:
	
		Timer(void);
		~Timer();
		Timer(const Timer& other);
		Timer&	operator=(const Timer& other);

		void	printTaskDuration(void);
		void	clockStart(void);
		void	clockStopper(void);
		void	clockReset(void);
	
	private:
		
		long long	_getTimeNow(void);
		/* data */
		long long	_start;
		long long	_stop;
};

#endif
