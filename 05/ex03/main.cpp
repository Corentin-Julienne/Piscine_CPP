/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:19 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:07:21 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat		*stalin = NULL;
	Bureaucrat		*trotsky = NULL;

	// initializing Comrade Stalin
	try
	{
		stalin = new Bureaucrat("Comrade Stalin", 1);
		std::cout << *stalin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// initializing Comrade Trotsky
	try
	{
		trotsky = new Bureaucrat("Comrade Trotsky", 150);
		std::cout << *trotsky << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	PresidentialPardonForm	*pardon = NULL;
	RobotomyRequestForm		*robot = NULL;
	ShrubberyCreationForm	*shrubbery = NULL;

	// initialize PresidentialPardonForm pardon
	try
	{
		pardon = new PresidentialPardonForm("Comrade Putin");
		std::cout << *pardon << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// initialize RobotomyRequestForm robot
	try
	{
		robot = new RobotomyRequestForm("Comrade Molotov");
		std::cout << *robot << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// initialize ShrubberyCreationForm shrubbery
	try
	{
		shrubbery = new ShrubberyCreationForm("red_shrubbery");
		std::cout << *shrubbery << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// CORE OF THE TEST PHASE
	
	stalin->executeForm(*pardon); 	  // should fail
	stalin->signForm(*pardon); 		  // should be a success
 	stalin->executeForm(*pardon); 	  // should be a success

	stalin->signForm(*robot); 		  // should be a sucess
	stalin->signForm(*shrubbery); 	  // should be a success

	trotsky->executeForm(*shrubbery); // should fail
	stalin->executeForm(*robot);      // should be a success
	stalin->executeForm(*shrubbery);  // should be a success
	
	// leaks killing
	
	delete stalin;
	delete trotsky;

	delete pardon;
	delete robot;
	delete shrubbery;
	//system("leaks MultiForms"); // debug only
	return (0);
}
