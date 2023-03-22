/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:34 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/22 11:21:15 by cjulienn         ###   ########.fr       */
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
		FJMI(std::list<int> unsorted_ints);
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

		
		/* common data */
		int									_last_val;
		/* algorithm using vectors */
		std::vector<int>					_unsorted_vect;
		std::vector<std::pair<int, int> >	_pairs_vect;
		std::vector<int>					_output_vect;
		std::vector<int>					_pend_vect;
		std::vector<int>					_jacob_seq;
		/* algorithm using lists */
		std::list<int>						_unsorted_list;
		std::list<std::pair<int, int> >		_pairs_list;
		std::list<int>						_output_list;
		std::list<int>						_pend_list;
};

#endif
