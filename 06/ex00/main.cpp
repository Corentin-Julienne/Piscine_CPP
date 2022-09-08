/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:23:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 16:06:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Converter.hpp"

int main(int argc, char **argv)
{
	std::string		input;

	if (argc != 2)
	{
		std::cout << "Error : wrong number of arguments !" << std::endl;
		return (1);
	}
	input = argv[1];

	Converter	*converter;

	try
	{
		converter = new Converter(input);
		std::cout << *converter << std::endl;
		delete converter;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//system("leaks convert"); // debug
	return (0);
}
