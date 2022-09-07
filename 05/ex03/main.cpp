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

	// TESTS OF EX03

	std::cout << "-------------------EX03 : TESTS------------------------" << std::endl << std::endl;

	Intern		Gulag_Prisoner;

	Form		*paper1 = NULL;
	Form		*paper2 = NULL;
	Form		*paper3 = NULL;
	Form		*paper4 = NULL;

	// try to create forms (those should work)

	try
	{
		paper1 = Gulag_Prisoner.makeForm("presidential pardon", "a lucky dude");
		std::cout << *paper1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		paper2 = Gulag_Prisoner.makeForm("shrubbery creation", "an ASCII botanist");
		std::cout << *paper2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		paper3 = Gulag_Prisoner.makeForm("robotomy request", "a communist robot");
		std::cout << *paper3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try to create an invalid form (should trigger exception)
	try
	{
		paper4 = Gulag_Prisoner.makeForm("Excommunicado", "John Wick");
		std::cout << *paper4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// leaks killing
	
	delete paper1;
	delete paper2;
	delete paper3;
	//system("leaks Interns"); // debug only
	return (0);
}
