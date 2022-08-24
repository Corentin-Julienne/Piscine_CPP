/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/12 16:59:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// other tests to kill after
	int		test = 1234;
	int		test_2 = 1234 << 8;
	float	flooat;

	std::cout << (test << 8) << " and " << (test_2 / (1 << 8)) << " and " << (test_2 >> 8)  << std::endl;
	flooat = (float)(test_2 / (1 << 8));
	std::cout << flooat << std::endl;
	return 0;
}
