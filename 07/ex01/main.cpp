/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:41:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 20:11:30 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

// testing procedure

/*
testing procedure works by trying various possible array types and use the iter function 
we provide tests for those types of arrays :
=> unsigned int
=> int
=> std::string
=> char
=> float
*/

int main(void)
{
	unsigned int	arr_ui[] = {34, 654354535, 998, 433};
	int				arr_int[] = {4232, -43434, 0, 43223};
	std::string		arr_str[] = {"alpha", "bravo", "charlie"};
	float			arr_float[] = {-42.42f, 0.0f, 42.42f};

	std::cout << "Test with unsigned int" << std::endl;
	::iter<unsigned int>(arr_ui, 4, displayer<unsigned int>);
	std::cout << "--------------------------------------------" << std::endl;
	
	std::cout << "Test with int" << std::endl;
	::iter<int>(arr_int, 4, displayer<int>);
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Test with string" << std::endl;
	::iter<std::string>(arr_str, 3, displayer<std::string>);
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Test with float" << std::endl;
	::iter<float>(arr_float, 3, displayer<float>);
	std::cout << "--------------------------------------------" << std::endl;

	return (0);
}
