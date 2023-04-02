/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:34 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 18:06:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJMI_HPP
# define FJMI_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

#include "PmergeMe.hpp"
#include "Timer.hpp"

/* the class FJMI is used to sort a vector of positive integers with a Ford-Johnson Merge Insert 
algorithm. Note that the vector should be used with valid values. The parsing of arguments
and the verification of data is handled by the PmergeMe class */

class PmergeMe;
class Timer;

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

		bool					areVectAndDeqEquivalent(void) const;

	private:
	
		FJMI(void);

		/* Jacobsthal numbers */
		int					_getJacobsthalNum(int index);
		bool				_isPertainingToJacob(std::deque<int> jacob_seq, int index);
		int					_nextJacobIndex(std::deque<int> jacob_seq, int index);
		std::deque<int>		_buildOptimalInsertionSeq(std::size_t pend_size);		

		/* recursive insertion sort for pairs and ints (with deque and vector) */
		void				_recursiveInsertionSort(std::vector<int>& array, int n);
		void				_recursiveInsertionSort(std::deque<int>& array, int n);
		void				_recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n);
		void				_recursiveInsertionSort(std::deque<std::pair<int, int> >& pairs, int n);
		
		/* template functions */

		template <typename Iter>
		void	_swapPairs(Iter it, Iter end)
		{
			int		tmp;
			
			for (; it != end; it++)
			{
				if (it->first > it->second)
				{
					tmp = it->first;
					it->first = it->second;
					it->second = tmp;
				}
			}
		}

		/* performs a search to know where to insert a new value into an already sorted array. 
		Works with random access iterators only !!! */
		template <typename Iter>
		Iter	_whereToInsertVal(Iter it, Iter end, int num)
		{			
			while (it != end)
			{
				if (num <= *it)
					return (it);
				it++;
			}
			return (end);
		}

		/* common data */
		int									_last_val;
		std::deque<int>						_jacob_insert_seq;
		/* algorithm using vectors */
		std::vector<int>					_unsorted_vect;
		std::vector<std::pair<int, int> >	_pairs_vect;
		std::vector<int>					_output_vect;
		std::vector<int>					_pend_vect;
		/* algorithm using lists */
		std::deque<int>						_unsorted_deque;
		std::deque<std::pair<int, int> >	_pairs_deque;
		std::deque<int>						_output_deque;
		std::deque<int>						_pend_deque;

		/* DEBUG */

		void		_displayUnsortedVect(void);
		void		_displayPairs(void);
		void		_displayPend(void);
		void		_displayOutput(void);
		void		_displayInsertionSeq(void);
};

#endif
