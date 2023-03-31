/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:20 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/23 15:33:37 by cjulienn         ###   ########.fr       */
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
		void	_displayVectResults(const FJMI& vect);
		
		void	_Timestamp(void);
		void	_EndOfTask(void);
		void	_displayTime(const std::string container, int size);

		/* utils */
		template <typename T>
		std::string	numberToStr(T num)
		{
			std::ostringstream		ss;
			
			ss << num;
			return (ss.str());
		}

		/* debugging */
		bool	_checkIfDequeIsSorted(void);
		bool	_checkIfVectIsSorted(void);
		
		/* data */
		std::vector<int>					vector_ints;
		std::deque<int>						deque_ints;
		long long int						clock;
		long long int						chrono;
};

#endif
