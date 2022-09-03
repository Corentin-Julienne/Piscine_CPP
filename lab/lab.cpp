/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:45:31 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 15:29:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	std::string	arg(argv[1]);
	
	char* p;
	long converted = strtol(arg.c_str(), &p, 10);
	if (*p) {
		// conversion failed because the input wasn't a number
		std::cout << "seems that conversion failed" << std::endl;

		std::string		suffix(p);
		std::cout << suffix << std::endl;
	}
	else {
		std::cout << converted << std::endl;
	}
	return (0);
}
