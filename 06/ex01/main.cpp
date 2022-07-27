/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:11:41 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/27 17:13:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Data			*example = new Data;
	uintptr_t		compression;
	
	// giving values to example members
	example->name = "John Doe" ;
	example->random_char = 'c';
	example->random_float = 42.42f;
	example->random_num = 42;

	// serialize
	compression = serialize(example);
	// deserialize
	Data	*recovery = deserialize(compression);
	// verificating that the values are actually the same
	std::cout << "Original values are : " << std::endl;
	std::cout << "example->name = " << example->name << std::endl;
	std::cout << "example->random_num = " << example->name << std::endl;
	std::cout << "example->random_float = " << example->name << std::endl;
	std::cout << "example->random_char = " << example->name << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "New values are : " << std::endl;
	std::cout << "recovery->name = " << example->name << std::endl;
	std::cout << "recovery->random_num = " << example->name << std::endl;
	std::cout << "recovery->random_float = " << example->name << std::endl;
	std::cout << "recovery->random_char = " << example->name << std::endl;

	// verification of pointer values
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Value of original pointer = "  << example << std::endl;
	std::cout << "Value of the recovery pointer = " << recovery << std::endl;

	// freeing memory
	delete example;
	delete recovery; // double free ?
	return (0);
}
