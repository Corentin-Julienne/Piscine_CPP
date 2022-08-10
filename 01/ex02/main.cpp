/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:43:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 16:54:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTN = &string;
	std::string		&stringREF = string;

	/* print memory addresses */

	// give the address operand to the string itself
	std::cout << &string << std::endl;
	// give the pointer only (point to the address of the str)
	std::cout << stringPTN <<std::endl;
	// give the address of the reference (which is an alias for the variable itself)
	std::cout << &stringREF <<std::endl;
	
	/* print string itself */

	// print the string itself
	std::cout << string << std::endl;
	// have to dereference the pointer to print the string
	std::cout << *stringPTN << std::endl;
	// the reference is an alias to the variable of type string (no modifs are necessary)
	std::cout << stringREF << std::endl;
	
	return (0);
}
