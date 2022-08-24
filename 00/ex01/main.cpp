/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:23:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 15:45:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string		user_input;
	PhoneBook		phonebook;
	
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
			phonebook.addCtctToDb();
		else if (!user_input.compare("SEARCH"))
			phonebook.displayPhonebook();
		else
			std::cout << "Please enter a valid command !" <<std::endl;
	}
	return (0);
}
