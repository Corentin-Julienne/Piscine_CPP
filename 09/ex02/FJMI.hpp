/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:34 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/23 15:54:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJMI_HPP
# define FJMI_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

/* the class FJMI is used to sort a vector of positive integers with a Ford-Johnson Merge Insert 
algorithm. Note that the vector should be used with valid values. The parsing of arguments
and the verification of data is handled by the PmergeMe class */

/*



*/

class FJMI
{
	public:
	
		FJMI(std::vector<int> unsorted_ints);
		FJMI(std::deque<int> unsorted_ints);
		~FJMI();
		FJMI(const FJMI& other);
		FJMI&	operator=(const FJMI& other);

		/* getters */
		const std::vector<int>&	getSortedVector(void) const;
		const std::deque<int>&	getSortedDeque(void) const;
	
	private:
	
		FJMI(void);

		bool				_checkIfWellSorted(std::vector<int> output, std::vector<int> gold_std);
		bool				_checkIfWellSorted(std::vector<std::pair<int, int> > output);
		void				_makeIntPairs(void);
		void				_recursiveInsertionSort(std::vector<int>& array, int n);
		void				_sortPairs(std::vector<std::pair<int, int> >& pairs, std::vector<int> array);
		/* Jacobsthal numbers */
		int					_getJacobsthalNum(int index);		

		
		void				_recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n);
		
		
		void				_sortEveryPairByIndex(void);
		void				_sortEveryPairByIterator(void);

		
		/* common data */
		int									_last_val;
		/* algorithm using vectors */
		std::vector<int>					_unsorted_vect;
		std::vector<std::pair<int, int> >	_pairs_vect;
		std::vector<int>					_output_vect;
		std::vector<int>					_pend_vect;
		std::vector<int>					_jacob_seq;
		/* algorithm using lists */
		std::deque<int>						_unsorted_deque;
		std::deque<std::pair<int, int> >	_pairs_deque;
		std::deque<int>						_output_deque;
		std::deque<int>						_pend_deque;
};

#endif
