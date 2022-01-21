/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:43:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/17 12:17:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTN = &string;
	std::string		&stringREF = string;

	std::cout << &string << std::endl;
	std::cout << stringPTN <<std::endl;
	std::cout << &stringREF <<std::endl;
	std::cout << *stringPTN <<std::endl;
	std::cout << stringREF <<std::endl;	
	return (0);
}
