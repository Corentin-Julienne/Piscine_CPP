/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:05:41 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 15:04:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

Test::Test()
{
	srand(time(NULL)); // time seed

	std::vector<int>	testing;

	for (std::size_t i = 0; i < 100; i++)
	{
		testing.push_back(rand() % 100);
	}

	this->insertionSort(testing, testing.size());

	for (std::size_t i = 0; i < testing.size(); i++)
		std::cout << "vector idx " << i << " = " << testing[i] << std::endl;

	int num = 666;
	
	std::vector<int>::iterator it = this->whereToInsertLastVal<std::vector<int>::iterator>(testing.begin(), testing.end(), num);

	std::cout << "display the insertion of last value" << std::endl;
	testing.insert(it, num);
	for (std::size_t i = 0; i < testing.size(); i++)
		std::cout << "vector idx " << i << " = " << testing[i] << std::endl;

	std::cout << "checking validity of Jacobsthal insertion sequence" << std::endl;

	std::vector<int> seq = this->buildOptimalInsertionSeq(testing);

	for (std::size_t i = 0; i < seq.size(); i++)
	{
		std::cout << "seq idx " << i << " =  " << seq[i] << std::endl;
	}
}

Test::~Test() {}

int		Test::binarySearch(std::vector<int>&array, int item, int low_idx, int high_idx)
{
	if (high_idx <= low_idx)
		return (item > array[low_idx] ? (low_idx + 1) : low_idx);
	
	int		mid = (low_idx + high_idx) / 2;

	if (item == array[mid])
		return (mid + 1);
	
	if (item > array[mid])
		return (this->binarySearch(array, item, mid + 1, high_idx));
	
	return (this->binarySearch(array, item, low_idx, mid -1));
}

void	Test::insertionSort(std::vector<int>& array, int n)
{
	int	loc, j, selected;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		selected = array[i];
		
		// find location where selected should be inserted
		loc = this->binarySearch(array, selected, 0, j);
		
		// move all elements after location to create space
		while (j >= loc)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = selected;
	}
}

/* Jacosthal Number */

int	Test::getJacobsthalNum(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;

	return (getJacobsthalNum(index - 1) + 2 * getJacobsthalNum(index - 2));
}

/* check wether the index is a Jacobsthal number */
bool	Test::isPertainingToJacob(std::vector<int> jacob_seq, int index) // to test
{
	std::vector<int>::iterator		beg = jacob_seq.begin();
	std::vector<int>::iterator		end = jacob_seq.end();
	
	while (beg != end)
	{
		if (*beg == index)
			return true;
		beg++;
	}
	return (false);
}

/* check what is the next Jacobsthal number. Can be either the index provided or the next 
available number is the Jacobsthal sequence. If there is not next number avalaible, returns -1 */
int	Test::nextJacobIndex(std::vector<int> jacob_seq, int index)
{
	for (std::size_t i = index; (int)i <= jacob_seq.back(); i++)
	{
		if (isPertainingToJacob(jacob_seq, i))
			return (i);	
	}
	return (-1); // case no next Jacobsthal number
}

std::vector<int>	Test::buildOptimalInsertionSeq(std::vector<int> pend)
{
	
	std::vector<int>			optimal_seq;
	std::vector<int>			jacob_seq;
	int							res;

	// retrieve a Jacobsthal sequence limited to the number of ints in pend
	for (std::size_t i = 0; i <= pend.size(); i++)
	{
		res = getJacobsthalNum(i);
		if ((std::size_t)res <= pend.size())
			jacob_seq.push_back(res);
		else
			break;
	}

	int		iter = 0;
	int		current = 0;

	while (iter < (int)pend.size())
	{
		current = nextJacobIndex(jacob_seq, iter);
		if (current == iter || current == -1) // case we got Jacobsthal number or no other Jacobsthal nums existing
			optimal_seq.push_back(iter);
		else if (current != iter) // case non Jacobsthal number
		{
			for (int i = current; i >= iter; i--)
				optimal_seq.push_back(i);
			iter = current;
		}
		iter++;
	}
	return (optimal_seq);
}
