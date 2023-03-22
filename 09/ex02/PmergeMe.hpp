/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:20 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/22 17:54:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <sys/time.h>

#include "FJMI.hpp"

class PmergeMe
{
	public:

		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		
	private:

		PmergeMe(void);

		bool	_checkIntValidity(std::string input);
		void	_makeIntPairs(void);

		void	_Timestamp(void);
		void	_EndOfTask(void);
		void	_displayTime(const std::string container, int size);

		// debug 
		
		std::vector<int>					vector_ints;
		std::list<int>						list_ints;
		long long int						clock;
		long long int						chrono;
};

#endif
