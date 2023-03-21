/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:13 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/19 16:00:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>

#include "Timer.hpp"

#define JACOB		1
#define NON_JACOB	2
#define START		3

int	getJacobsthalNum(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
 
    return (getJacobsthalNum(index - 1) + 2 * getJacobsthalNum(index - 2));
}

std::vector<int>	generateRandomNums(int quantity)
{
	std::vector<int>		random_nums;
	
	srand((unsigned) time(NULL));
	while (quantity > 0)
	{
		// Get a random number between 0 and 99
		int random = rand() % 20;
		random_nums.push_back(random);
		quantity--;		
	}
	return (random_nums);
}

void	recursiveInsertionSort(std::vector<std::pair<int, int> >& pairs, int n) // test that shit
{
	if (n <= 1) // case only one int in the array, no need to sort this 
		return;
	
	recursiveInsertionSort(pairs, n - 1);

	std::pair<int, int>		last = pairs[n - 1];	
	int						j = n - 2;

	while (j >= 0 && pairs[j].second > last.second)
	{
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = last;
}



/* check wether the index is a Jacobsthal number */
bool	isPertainingToJacob(std::deque<int> jacob_seq, int index) // to test
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
int	nextJacobIndex(std::deque<int> jacob_seq, int index)
{
	for (std::size_t i = index; (int)i <= jacob_seq.back(); i++)
	{
		if (isPertainingToJacob(jacob_seq, i))
			return (i);	
	}
	return (-1); // case no next Jacobsthal number
}

/* returns a deque with the optimal order of insertion based on Jacobsthal numbers */
std::deque<int>	buildOptimalInsertionSeq(std::vector<int> pend)
{
	Timer("Insertion Sequence Clock");
	
	std::deque<int>			optimal_seq;
	std::deque<int>			jacob_seq;
	int						res;

	// retrieve a Jacobsthal sequence limited to the number of ints in pend
	for (std::size_t i = 0; i <= pend.size(); i++)
	{
		res = getJacobsthalNum(i);
		if ((std::size_t)res <= pend.size())
			jacob_seq.push_back(res);
		else
			break;
	}

	std::cout << " displaying jacob seq" << std::endl;
	for (std::size_t i = 0; i < jacob_seq.size(); i++)
		std::cout << "number [" << i + 1 << "] = |" << jacob_seq[i] << "|" << std::endl;

	int		iter = 0;
	int		current = 0;

	while (iter < (int)pend.size())
	{
		current = nextJacobIndex(jacob_seq, iter);
		std::cout << "iter = " << iter << " and current = " << current << std::endl;
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

int main(int argc, char **argv)
{
	Timer	main_func("Main Clock");
	
	if (argc != 2)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}
		
	std::vector<int>	randomizer = generateRandomNums(atoi(argv[1])); // genrate random input
	
	for (std::size_t i = 0; i < randomizer.size(); i++)
		std::cout << "random num |" << i << "| = |" << randomizer[i] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	std::vector<std::pair<int, int> >	pairs;

	for (std::size_t i = 0; i < randomizer.size(); i += 2) // pairs input
		pairs.push_back(std::pair<int, int>(randomizer[i], randomizer[i + 1]));
	
	int		tmp;
	for (std::size_t i = 0; i < pairs.size(); i++) // sort the two pair members
	{
		if (pairs[i].first > pairs[i].second)
		{
			tmp = pairs[i].second;
			pairs[i].second = pairs[i].first;
			pairs[i].first = tmp;
		}
	}	

	recursiveInsertionSort(pairs, pairs.size()); // sort the pairs

	std::cout << "testing sorted pairs based on second element" << std::endl << std::endl;
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "index = " << i <<  ", second pair elem = |" << pairs[i].second
		<< "| and first elem = |" << pairs[i].first << "|" << std::endl;
	}

	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "go for insertion protocol" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;


	std::vector<int>		output;
	std::vector<int>		pend;

	for (std::size_t i = 0; i < pairs.size(); i++) // phase 5 and 6
	{
		pend.push_back(pairs[i].first);
		output.push_back(pairs[i].second);
	}

	std::cout << "displaying output" << std::endl;
	for (std::size_t i = 0; i <  output.size(); i++)
		std::cout << "index [" << i << "] = |" << output[i] << "|" << std::endl;
	
	std::cout << std::endl << "displaying pend" << std::endl;
	for (std::size_t i = 0; i < pend.size(); i++)
		std::cout << "index [" << i << "] = |" << pend[i] << "|" << std::endl;

	std::cout << "------------------------------------" << std::endl;
	std::cout << "insert with Jacobsthal numbers" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	std::deque<int>		insert_seq = buildOptimalInsertionSeq(pend);
	std::cout << "go after last function" << std::endl;
	
	std::cout << "size of insert_seq = " << insert_seq.size() << std::endl;

	std::cout << "displaying optimal insertion sequence" << std::endl;
	for (std::size_t i = 0; i < insert_seq.size(); i++)
		std::cout << "index [" << i << "] = |" << insert_seq[i] << "|" << std::endl;



	

	return (0);
}
