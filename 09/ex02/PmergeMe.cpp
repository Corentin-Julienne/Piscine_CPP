/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:24:18 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/17 11:58:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PmergeMe implement a Ford-Johnson Merge Insert algorithm */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {} // private, don't use it

PmergeMe::PmergeMe(char **argv)
{
	std::string			input;
	std::string			token;
	
	for (std::size_t i = 0; argv && argv[i]; i++)
	{
		input += " ";
		input += argv[i];
		input += " ";
	}
	if (input.find_first_not_of(" \t\n\v\f\r") != std::string::npos)
		throw std::runtime_error("Error");
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
			this->unsorted_ints.push_back(atoi(token.c_str())); // if int valid
		}
	}
	// debug
	std::cout << "----------------------------------" << std::endl;
	for (std::size_t i = 0; i < this->unsorted_ints.size(); i++)
		std::cout << "num : " << i << " = |" << this->unsorted_ints[i] << "|"  << std::endl;	
	std::cout << "----------------------------------" << std::endl;
	// end of debug	
	
	FJMI		results(this->unsorted_ints);
}


PmergeMe::PmergeMe(const PmergeMe& other)
{
	
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{

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
