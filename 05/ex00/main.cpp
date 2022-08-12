/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:19:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 17:23:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

int	main(void)
{
	Bureaucrat	stalin("Comrade Stalin", 1);
	Bureaucrat	trotsky("Comrade Trotsky", 150);

	// check if bureaucrat have the adequate rank
	try 
	{
		std::cout << stalin << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try to increment Comrade Stalin rank (should throw an error)
	try
	{
		stalin.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try to decrement Comrade Trotsky rank (should throw an error)
	try
	{
		trotsky.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
