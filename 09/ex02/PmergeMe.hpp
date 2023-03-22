/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:20 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/21 17:57:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

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

		// debug 
		
		std::vector<int>					vector_ints;
		std::deque<int>						deque_ints;
};

#endif
