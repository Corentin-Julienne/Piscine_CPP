/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:20 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 15:31:05 by cjulienn         ###   ########.fr       */
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
#include <sstream>

#include "FJMI.hpp"
#include "Timer.hpp"

class FJMI;
class Timer;

class PmergeMe
{
	public:

		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		
	private:

		PmergeMe(void); // don't use that !!!

		bool	_checkIntValidity(std::string input);
		void	_displayVectResults(const FJMI& vect);
	
		/* utils */
		template <typename T>
		std::string	numberToStr(T num)
		{
			std::ostringstream		ss;
			
			ss << num;
			return (ss.str());
		}
		
		/* data */
		std::vector<int>					vector_ints;
		std::deque<int>						deque_ints;

		/* debugging */
		void	_areResultsValid(const FJMI& vect, const FJMI& deq);
};

#endif
