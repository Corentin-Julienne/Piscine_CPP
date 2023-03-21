/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:34 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/18 10:53:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJMI_HPP
# define FJMI_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

/* the class FJMI is used to sort a vector of positive integers with a Ford-Johnson Merge Insert 
algorithm. Note that the vector should be used with valid values. The parsing of arguments
and the verification of data is handled by the PmergeMe class */

/*



*/

class FJMI
{
	public:
	
		FJMI(std::vector<int> unsorted_int);
		~FJMI();
		FJMI(const FJMI& other);
		FJMI&	operator=(const FJMI& other);
	
	private:
	
		FJMI(void);

		bool				_checkIfWellSorted(std::vector<int> output, std::vector<int> gold_std);
		bool				_checkIfWellSorted(std::vector<std::pair<int, int> > output);
		void				_makeIntPairs(void);
		void				_sortEveryPair(void);
		void				_recursiveInsertionSort(std::vector<int>& array, int n);
		void				_recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n);
		void				_sortPairs(std::vector<std::pair<int, int> >& pairs, std::vector<int> array);
		/* Jacobsthal numbers */
		int					_getJacobsthalNum(int index);		

		int									_last_val;
		std::vector<int>					_unsorted_ints;
		std::vector<std::pair<int, int> >	_pairs;
		std::deque<int>						_output;
		std::deque<int>						_pend;
		std::vector<int>					_jacob_seq;
};

#endif
