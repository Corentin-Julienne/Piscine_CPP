/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:19:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/31 18:57:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

int	main(void)
{
	Bureaucrat	*stalin = NULL;
	Bureaucrat	*trotsky = NULL;
	Bureaucrat	*gorbatchev = NULL;
	
	// COMRADE STALIN (GO GULAG !!!!)
	try
	{
		stalin = new Bureaucrat("Comrade Stalin", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// display bureaucrat rank
	std::cout << *stalin << std::endl;
	// try to increment Comrade Stalin rank (should throw an error)
	try
	{
		stalin->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// COMRADE TROTSKY
	try
	{
		trotsky = new Bureaucrat("Comrade Trotsky", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try to decrement Comrade Trotsky rank (should throw an error)
	try
	{
		trotsky->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// COMRADE GORBATCHEV [RIP]
	try
	{
		gorbatchev = new Bureaucrat("Comrade Gorbatchev", 444);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// free heap to avoid leaks
	delete stalin;
	delete trotsky;
	delete gorbatchev;
	system("leaks Bureaucrat");
		
	return (0);
}
