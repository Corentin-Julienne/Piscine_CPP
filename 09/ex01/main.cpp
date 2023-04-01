/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:47 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/01 12:41:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Calculate an RPN expression */
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: the programm accepts at least one argument" << std::endl;
		return (1);
	}
	try
	{
		RPN		test(argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
