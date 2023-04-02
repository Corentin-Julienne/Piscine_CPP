/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:18 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PmergeMe implement a Ford-Johnson Merge Insert algorithm */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {} // private, don't use it

/* Constructor to use. Will convert arguments into a string (with ' ' between args) */
PmergeMe::PmergeMe(char **argv)
{
	std::string			input;
	std::string			token;
	
	for (std::size_t i = 1; argv && argv[i]; i++)
	{
		input += " ";
		input += argv[i];
		input += " ";
	}
	for (std::size_t i = 0; i < input.size(); i++)
	{
		if (std::isspace(input[i]) && input[i] != ' ')
			input[i] = ' ';
	}

	std::stringstream	ss(input);

	while (!ss.eof())
	{
		std::getline(ss, token, ' ');
		if (!token.empty())
		{
			if (!this->_checkIntValidity(token))
				throw std::runtime_error("Error");
			this->vector_ints.push_back(atoi(token.c_str()));
			this->deque_ints.push_back(atoi(token.c_str()));
		}
	}

	/* algorithm treatment and displaying results and time consumed */

	/* with vector */
	Timer		vectClock;
	vectClock.clockStart();
	FJMI		with_vect(this->vector_ints);
	vectClock.clockStopper();
	this->_displayVectResults(with_vect);
	std::cout << "Time to proceed a range of " << with_vect.getSortedVector().size() << " with std::vector ";
	vectClock.printTaskDuration();
	
	/* with deque */
	Timer		deqClock;
	deqClock.clockStart();
	FJMI		with_deq(this->deque_ints);
	deqClock.clockStopper();
	std::cout << "Time to proceed a range of " << with_deq.getSortedDeque().size() << " with std::deque ";
	deqClock.printTaskDuration();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->vector_ints = other.vector_ints;
	this->deque_ints = other.deque_ints;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->vector_ints = other.vector_ints;
		this->deque_ints = other.deque_ints;
	}
	return *this;
}

/* checks whether the string input is a positive integer inferior to
INT_MAX. Returns true if it is the case, false otherwise */
bool	PmergeMe::_checkIntValidity(std::string input)
{
	long int		limit_checker;
	
	for (std::size_t i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	if (input.size() > 10) // case more than int limits 
		return (false);
	limit_checker = std::strtol(input.c_str(), NULL, 10);
	if (limit_checker > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

/* print all the results */
void	PmergeMe::_displayVectResults(const FJMI& vect) // to test
{
	std::string		unsorted_res;
	std::string		sorted_res;

	for (std::size_t i = 0; i < this->vector_ints.size(); i++)
	{
		unsorted_res += this->numberToStr<int>(this->vector_ints[i]);
		if (i != this->vector_ints.size() - 1)
			unsorted_res += " ";
	}

	std::vector<int>	cpy = vect.getSortedVector();

	for (std::size_t i = 0; i < cpy.size(); i++)
	{
		sorted_res += this->numberToStr<int>(cpy[i]);
		if (i != cpy.size() - 1)
			sorted_res += " ";
	}
	
	std::cout << "Before	" << unsorted_res << std::endl;
	std::cout << "After		" << sorted_res << std::endl;
}

/* DEBUG */

/* check if the parsing has been successful */
void	PmergeMe::_displayUnsortedDataStructs(void)
{
	std::cout << "Displaying vector with " << this->vector_ints.size() << " elements" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (std::size_t i = 0; i < this->vector_ints.size(); i++)
		std::cout << "num : " << i << " = |" << this->vector_ints[i] << "|"  << std::endl;	
	std::cout << "----------------------------------" << std::endl;

	std::cout << "Displaying deque with " << this->deque_ints.size() << " elements" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (std::size_t i = 0; i < this->deque_ints.size(); i++)
		std::cout << "num : " << i << " = |" << this->deque_ints[i] << "|"  << std::endl;	
	std::cout << "----------------------------------" << std::endl;
}
