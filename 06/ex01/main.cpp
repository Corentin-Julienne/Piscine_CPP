/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:11:41 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/27 17:21:17 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

/*

IMPORTANT THEORETICAL POINT : the typedef uintptr_t pointer
assure the user that if you cast it from a pointer of a given object and
recast it after it wont change the pointer value or alter the memory

*/

int main(void)
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
	std::cout << "example->random_num = " << example->random_num << std::endl;
	std::cout << "example->random_float = " << example->random_float << std::endl;
	std::cout << "example->random_char = " << example->random_char << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "New values are : " << std::endl;
	std::cout << "recovery->name = " << recovery->name << std::endl;
	std::cout << "recovery->random_num = " << recovery->random_num << std::endl;
	std::cout << "recovery->random_float = " << recovery->random_float << std::endl;
	std::cout << "recovery->random_char = " << recovery->random_char << std::endl;

	// verification of pointer values
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Value of original pointer = "  << example << std::endl;
	std::cout << "Value of the recovery pointer = " << recovery << std::endl;

	// freeing memory
	delete example;
	return (0);
}
