/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:23:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 15:57:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	std::string		user_input;
	Phonebook		phonebook;
	
	std::cout << "Welcome to a nice 80's style crappy notebook!" << std::endl;
	std::cout << std::endl << std::endl;
	while (42)
	{
		std::cout << "Enter ADD to add a contact ";
		std::cout << "SEARCH to retrieve contact data ";
		std::cout << "or EXIT to exit the programm" << std::endl;
		std::cout << std::endl;
		std::getline(std::cin, user_input);
		if (!user_input.compare("EXIT"))
		{
			std::cout << "exiting programm ! Bye !" << std::endl;
			return (0);
		}
		else if (!user_input.compare("ADD"))
			phonebook.add_ctct_to_db();
		else if (!user_input.compare("SEARCH"))
			phonebook.display_phonebook();
		else
			std::cout << "Please enter a valid command !" <<std::endl;
	}
	return (0);
}
