/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:32 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/17 17:33:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FJMI.hpp"

FJMI::FJMI(void) {}

FJMI::FJMI(std::vector<int> unsorted_ints) : _unsorted_ints(unsorted_ints), _last_val(-1)
{
	/* phase 1 */
	if (_unsorted_ints.size() % 2 != 0)
	{
		_last_val = _unsorted_ints.back();
		_unsorted_ints.pop_back();
	}
	/* phase 2 */
	for (std::size_t i = 0; i < _unsorted_ints.size(); i += 2)
		_pairs.push_back(std::pair<int, int>(_unsorted_ints[i], _unsorted_ints[i + 1]));
	/* phase 3 */
	this->_sortEveryPair();
	/* phase 4 */
	this->_recursiveInsertionSort(_pairs, _pairs.size());
	if (!this->_checkIfWellSorted(_pairs))
		std::cerr << "problem with recursive insertion sort (phase 4)" << std::endl;
	/* phase 5 and 6 */
	for (std::size_t i = 0; i < _pairs.size(); i++)
	{
		_pend.push_back(_pairs[i].first);
		_output.push_back(_pairs[i].second);
	}
	/* phase 7 */
	for (std::size_t i = 0; i < _pend.size(); i++)
		_jacob_seq.push_back(this->_getJacobsthalNum(i));
	
	/* phase 9 */
	if (_last_val != -1)
		; // implement phase 9
	if (!this->_checkIfWellSorted(_output)) // debug after all algo
		std::cerr << "final output is not well sorted" << std::endl;
}

/* returns the nth number of the Jacobsthal Sequence */
int	FJMI::_getJacobsthalNum(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
 
    return (this->_getJacobsthalNum(index - 1) + 2 * this->_getJacobsthalNum(index - 2));
}

/* use the insertion sort algorithm in a recursive way (use second element of pair to compare) */
void	FJMI::_recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n) // test that shit
{
	if (n <= 1) // case only one int in the array, no need to sort this 
		return;
	
	this->_recursiveInsertionSort(pairs, n - 1);

	std::pair<int, int>		last = pairs[n - 1];	
	int						j = n - 2;

	while (j >= 0 && pairs[j].second > last.second)
	{
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = last;
}

/* use the insertion sort algorithm in a recursive way */
void	FJMI::_recursiveInsertionSort(std::vector<int>& array, int n)
{
	if (n <= 1) // case only one int in the array, no need to sort this 
        return;
		
	this->_recursiveInsertionSort(array, n - 1);

	int last = array[n - 1];
    int j = n - 2;

	while (j >= 0 && array[j] > last)
    {
        array[j + 1] = array[j];
        j--;
    }
     
	array[j + 1] = last;
}

/* inside every pair, sort the two ints in ascending order */
void	FJMI::_sortEveryPair(void) // to test
{
	int			tmp;
	
	for (std::size_t i = 0; i < _pairs.size(); i++)
	{
		if (_pairs[i].first > _pairs[i].second)
		{
			tmp = _pairs[i].first;
			_pairs[i].first = _pairs[i].second;
			_pairs[i].second = tmp;
		}
	}
}

FJMI::~FJMI() {}

FJMI::FJMI(const FJMI& other)
{
	
}

FJMI&	FJMI::operator=(const FJMI& other)
{
	if (this != &other)
	{

	}
	return *this;
}

/* compare the results with a quicksort provided by algorithm to see
whether or not is is correctly sorted */
bool	FJMI::_checkIfWellSorted(std::vector<int> output, std::vector<int> gold_std) // to test
{	
	std::sort(gold_std.begin(), gold_std.end());
	if (gold_std.size() != output.size())
		return (false);
	for (std::size_t i = 0; i < gold_std.size(); i++)
	{
		if (gold_std[i] != output[i])
			return (false);	
	}
	return (true);
}

/*compare the results with a quicksort provided by algorithm to see
whether or not is is correctly sorted (use second element of pair for comparison)*/
bool	FJMI::_checkIfWellSorted(std::vector<std::pair<int, int> > output) // to test
{
	std::vector<int>		second_elems;
	std::vector<int>		gold_std;

	for (std::size_t i = 0; i < output.size(); i++)
		second_elems.push_back(output[i].second);
	gold_std = second_elems;
	std::sort(gold_std);
	return (this->_checkIfWellSorted(second_elems, gold_std));
}
