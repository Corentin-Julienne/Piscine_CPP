/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:32 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 14:59:10 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FJMI.hpp"

/* constructor for deque */
FJMI::FJMI(std::deque<int> unsorted_ints) :  _last_val(-1), _unsorted_deque(unsorted_ints)
{
	/* phase 1 */
	if (_unsorted_deque.size() % 2 != 0)
	{
		_last_val = _unsorted_deque.back();
		_unsorted_deque.pop_back();
	}
	/* phase 2 */
	for (std::size_t i = 0; i < _unsorted_deque.size(); i += 2)
		_pairs_deque.push_back(std::pair<int, int>(_unsorted_deque[i], _unsorted_deque[i + 1]));	
	/* phase 3 */
	this->_swapPairs<std::deque<std::pair<int, int> >::iterator>(this->_pairs_deque.begin(), this->_pairs_deque.end());	
	/* phase 4 */
	this->_recursiveInsertionSort(_pairs_deque, _pairs_deque.size());
	/* phase 5 and 6 */
	for (std::size_t i = 0; i < _pairs_deque.size(); i++)
	{
		_pend_deque.push_back(_pairs_deque[i].first);
		_output_deque.push_back(_pairs_deque[i].second);
	}
	/* phase 7 */
	this->_jacob_insert_seq = this->_buildOptimalInsertionSeq(_pend_deque.size() + 1);
	/* phase 8 */
	int								val_to_insert;
	std::deque<int>::iterator		it;
	
	for (std::size_t i = 0; i < _pend_deque.size(); i++)
	{
		val_to_insert = this->_pend_deque[this->_jacob_insert_seq[i] - 1];
		it = this->_whereToInsertVal<std::deque<int>::iterator>(_output_deque.begin(), _output_deque.end(), val_to_insert);
		if (it != _output_deque.end())
			_output_deque.insert(it, val_to_insert);
	}
	/* phase 9 */
	std::deque<int>::iterator	it_last;
	
	if (_last_val != (-1))
	{
		it_last = this->_whereToInsertVal<std::deque<int>::iterator>(_output_deque.begin(),
			_output_deque.end(), _last_val);

		_output_deque.insert(it_last, _last_val);
	}
}

/* constructor with vector */
FJMI::FJMI(std::vector<int> unsorted_ints) : _last_val(-1), _unsorted_vect(unsorted_ints)
{
	/* phase 1 */
	if (_unsorted_vect.size() % 2 != 0)
	{
		_last_val = _unsorted_vect.back();
		_unsorted_vect.pop_back();
	}
	/* phase 2 */
	for (std::size_t i = 0; i < _unsorted_vect.size(); i += 2)
		_pairs_vect.push_back(std::pair<int, int>(_unsorted_vect[i], _unsorted_vect[i + 1]));
	/* phase 3 */
	this->_swapPairs<std::vector<std::pair<int, int> >::iterator>(this->_pairs_vect.begin(), this->_pairs_vect.end());
	/* phase 4 */
	this->_recursiveInsertionSort(_pairs_vect, _pairs_vect.size());
	/* phase 5 and 6 */
	for (std::size_t i = 0; i < _pairs_vect.size(); i++)
	{
		_pend_vect.push_back(_pairs_vect[i].first);
		_output_vect.push_back(_pairs_vect[i].second);
	}
	/* phase 7 */
	this->_jacob_insert_seq = this->_buildOptimalInsertionSeq(_pend_vect.size() + 1);
	/* phase 8 */
	int								val_to_insert;
	std::vector<int>::iterator		it;
	
	for (std::size_t i = 0; i < _pend_vect.size(); i++)
	{
		val_to_insert =  this->_pend_vect[this->_jacob_insert_seq[i] - 1];
		it = this->_whereToInsertVal<std::vector<int>::iterator>(_output_vect.begin(), _output_vect.end(), val_to_insert);
		_output_vect.insert(it, val_to_insert);
	}
	/* phase 9 */
	std::vector<int>::iterator	it_last;
	
	if (_last_val != (-1))
	{
		it_last = this->_whereToInsertVal<std::vector<int>::iterator>(_output_vect.begin(),
			_output_vect.end(), _last_val);

		_output_vect.insert(it_last, _last_val);
	}
}

FJMI::~FJMI() {}

FJMI::FJMI(const FJMI& other)
{
	this->_last_val	= other._last_val;
	this->_jacob_insert_seq = other._jacob_insert_seq;

	this->_unsorted_vect = other._unsorted_vect;
	this->_pairs_vect = other._pairs_vect;
	this->_output_vect = other._output_vect;
	this->_pend_vect = other._pend_vect;

	this->_unsorted_deque = other._unsorted_deque;
	this->_pairs_deque = other._pairs_deque;
	this->_output_deque = other._output_deque;
	this->_pend_deque = other._pend_deque;
}

FJMI&	FJMI::operator=(const FJMI& other)
{
	if (this != &other)
	{
		this->_last_val	= other._last_val;
		this->_jacob_insert_seq = other._jacob_insert_seq;

		this->_unsorted_vect = other._unsorted_vect;
		this->_pairs_vect = other._pairs_vect;
		this->_output_vect = other._output_vect;
		this->_pend_vect = other._pend_vect;

		this->_unsorted_deque = other._unsorted_deque;
		this->_pairs_deque = other._pairs_deque;
		this->_output_deque = other._output_deque;
		this->_pend_deque = other._pend_deque;
	}
	return *this;
}

/* GETTERS */
const std::vector<int>&	FJMI::getSortedVector(void) const { return this->_output_vect; }
const std::deque<int>&	FJMI::getSortedDeque(void) const { return this->_output_deque; }

/* PUBLIC FUNCTIONS */

/* check whether the sorted deque and vector are similar in size and sorting order */
bool	FJMI::areVectAndDeqEquivalent(void) const
{
	if (this->_output_deque.size() != this->_output_vect.size())
		return (false);
	for (std::size_t i = 0; i < this->_output_vect.size(); i++)
	{
		if (this->_output_deque[i] != this->_output_vect[i])
			return (false);
	}
	return (true);
}

/* PRIVATE HELPER FUNCTIONS */

/* Jacobsthal numbers helpers */

/* returns the nth number of the Jacobsthal Sequence */
int	FJMI::_getJacobsthalNum(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
 
    return (this->_getJacobsthalNum(index - 1) + 2 * this->_getJacobsthalNum(index - 2));
}

/* check wether the index is a Jacobsthal number */
bool	FJMI::_isPertainingToJacob(std::deque<int> jacob_seq, int index) // to test
{
	std::deque<int>::iterator		beg = jacob_seq.begin();
	std::deque<int>::iterator		end = jacob_seq.end();
	
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
int	FJMI::_nextJacobIndex(std::deque<int> jacob_seq, int index)
{
	for (std::size_t i = index; (int)i <= jacob_seq.back(); i++)
	{
		if (this->_isPertainingToJacob(jacob_seq, i))
			return (i);	
	}
	return (-1); // case no next Jacobsthal number
}

std::deque<int>	FJMI::_buildOptimalInsertionSeq(std::size_t pend_size)
{
	
	std::deque<int>			optimal_seq;
	std::deque<int>			jacob_seq;
	int						res;

	// retrieve a Jacobsthal sequence limited to the number of ints in pend
	for (std::size_t i = 0; i <= pend_size; i++)
	{
		res = this->_getJacobsthalNum(i);
		if ((std::size_t)res <= pend_size)
			jacob_seq.push_back(res);
		else
			break;
	}

	int		iter = 0;
	int		current = 0;

	while ((std::size_t)iter < pend_size)
	{
		current = this->_nextJacobIndex(jacob_seq, iter);
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
	optimal_seq.pop_front();
	return (optimal_seq);
}

/* recursive insertion sort for std::vector and std::deque (with single int values and pairs of int) */

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

void	FJMI::_recursiveInsertionSort(std::deque<int>& array, int n)
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

void	FJMI::_recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n)
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

void	FJMI::_recursiveInsertionSort(std::deque<std::pair<int, int> >& pairs, int n)
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

/* DEBUG */

void	FJMI::_displayUnsortedVect(void)
{
	std::cout << "Displaying unsorted vector..." << std::endl;
	for (std::size_t i = 0; i < this->_unsorted_vect.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _unsorted_vect[i] << "|" << std::endl;
	}
}

void	FJMI::_displayUnsortedDeq(void)
{
	std::cout << "Displaying unsorted deque..." << std::endl;
	for (std::size_t i = 0; i < this->_unsorted_deque.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _unsorted_deque[i] << "|" << std::endl;
	}
}

void	FJMI::_displayVectPairs(void)
{
	std::cout << "Displaying pairs..." << std::endl;
	for (std::size_t i = 0; i < this->_pairs_vect.size(); i++)
	{
		std::cout << "pair num " << i << " = [" << _pairs_vect[i].first << ", "
		<< _pairs_vect[i].second << "]" << std::endl;
	}	
}

void	FJMI::_displayDeqPairs(void)
{
	std::cout << "Displaying pairs..." << std::endl;
	for (std::size_t i = 0; i < this->_pairs_deque.size(); i++)
	{
		std::cout << "pair num " << i << " = [" << _pairs_deque[i].first << ", "
		<< _pairs_deque[i].second << "]" << std::endl;
	}	
}

void	FJMI::_displayVectPend(void)
{
	std::cout << "Displaying pend..." << std::endl;
	for (std::size_t i = 0; i < this->_pend_vect.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _pend_vect[i] << "|" << std::endl;
	}	
}

void	FJMI::_displayDeqPend(void)
{
	std::cout << "Displaying pend..." << std::endl;
	for (std::size_t i = 0; i < this->_pend_deque.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _pend_deque[i] << "|" << std::endl;
	}	
}

void	FJMI::_displayVectOutput(void)
{
	std::cout << "Displaying output..." << std::endl;
	for (std::size_t i = 0; i < this->_output_vect.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _output_vect[i] << "|" << std::endl;
	}	
}

void	FJMI::_displayDeqOutput(void)
{
	std::cout << "Displaying output..." << std::endl;
	for (std::size_t i = 0; i < this->_output_deque.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _output_deque[i] << "|" << std::endl;
	}	
}

void	FJMI::_displayInsertionSeq(void)
{
	std::cout << "Display Jacobsthal Insertion Sequence..." << std::endl;
	for (std::size_t i = 0; i < this->_jacob_insert_seq.size(); i++)
	{
		std::cout << "index [" << i << "] = |" << _jacob_insert_seq[i] << "|" << std::endl;
	}	
}
