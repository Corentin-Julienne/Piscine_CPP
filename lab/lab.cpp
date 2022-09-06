/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:45:31 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/05 15:32:58 by cjulienn         ###   ########.fr       */
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
	float converted = strtof(arg.c_str(), &p);
	if (*p)
		std::cout << "conversion failed" << std::endl;
	std::cout << static_cast<char>(converted) << std::endl;
	
	//std::cout << static_cast<float>(converted) << std::endl;
	
	
	return (0);
}
