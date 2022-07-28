/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:41:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/28 15:27:04 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

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
	
	::iter<unsigned int>(arr_ui, 4, displayer<unsigned int>);
	::iter<int>(arr_int, 4, displayer<int>);
	::iter<std::string>(arr_str, 3, displayer<std::string>);
	::iter<float>(arr_float, 3, displayer<float>);
	
	return (0);
}
