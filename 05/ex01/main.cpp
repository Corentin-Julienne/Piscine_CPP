/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:13:19 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 12:07:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	*stalin = NULL;
	Bureaucrat	*trotsky = NULL;
	
	// initializing Comrade Stalin
	try
	{
		stalin = new Bureaucrat("Comrade Stalin", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// initializing Comrade Trotsky
	try
	{
		trotsky = new Bureaucrat("Comrade Trotsky", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Form		*gulag = NULL;
	Form		*execution = NULL;

	// initialize gulag form
	try
	{
		gulag = new Form("Gulag Emprisonment Form", 17, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// initialize execution form
	try
	{
		execution = new Form("Death Sentence Form", 85, 68);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// proper testing phase

	// comrade Stalin want to send someone to gulag (should work, he's comrade Stalin after all)
	stalin->signForm(*gulag);
	std::cout << *gulag << std::endl; // check form status

	// comrade Trotsky want to sign someone's execution order (should fail)
	trotsky->signForm(*execution);
	std::cout << *execution << std::endl;

	// delete everything ont the heap
	delete stalin;
	delete trotsky;
	delete gulag;
	delete execution;
	//system("leaks Forms"); // to debug use only, comment after use
	return (0);
}
