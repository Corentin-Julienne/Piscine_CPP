/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:22:50 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/02 16:19:49 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include "FJMI.hpp"
#include "Timer.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "the program must take one or several arguments" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	MergeAndInsert(argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
