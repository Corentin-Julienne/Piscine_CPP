/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:41 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 14:51:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>
#include <map>
#include <ctime>

class Test
{
	public:
	
		Test();
		~Test();


		int					getJacobsthalNum(int index);
		bool				isPertainingToJacob(std::vector<int> jacob_seq, int index);
		int					nextJacobIndex(std::vector<int> jacob_seq, int index);
		std::vector<int>	buildOptimalInsertionSeq(std::vector<int> pend);

		int		binarySearch(std::vector<int>& array, int item, int low_idx, int high_idx);
		void	insertionSort(std::vector<int>& array, int n);

		
		template <typename Iter>
		Iter	whereToInsertLastVal(Iter it, Iter end, int num)
		{			
			while (it != end)
			{
				if (num <= *it)
					return (it);
				it++;
			}
			return (end);
		}

		template <typename Iter>
		void	swapPairs(Iter it, Iter end)
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

	private:
		
		std::vector<std::pair<int, int> >	vect;
		std::deque<std::pair<int, int> >	deq;
};

#endif
