/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:07 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 11:31:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << "----------Tests provided by subject-------------" << std::endl;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "----------Tests provided by student-------------" << std::endl;

	Fixed c (Fixed( 5.05f ) / Fixed (2) );
	Fixed d (Fixed( 5.05f ) + Fixed( 2 ));
	Fixed e (Fixed( 5.05f ) - Fixed( 2 ));
	Fixed f (c);

	std::cout << "c = " << c << std::endl; // should output about 2.525
	std::cout << "d = " << d << std::endl; // should output about 7.05
	std::cout << "e = " << e << std::endl; // should output about 3.05
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "the minimum of " << c  << " and " << d << "is " << Fixed::min( c, d ) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	// checking comparison operators
	std::cout << "---------------------------------------------" << std::endl;
	if (c == f)
		std::cout << c << " and " << f << " have the same value" << std::endl;
	else
		std::cout << c << " and " << f << " have different values" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c != d)
		std::cout << c << " and " << d << " are not equivalent" << std::endl;
	else
		std::cout << c << " and " << d << " are equivalent" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c < d)
		std::cout << c  << " is inferior to " << d << std::endl;
	else
		std::cout << c  << " is not inferior to " << d << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c > d)
		std::cout << c  << " is superior to " << d << std::endl;
	else
		std::cout << c  << " is not superior to " << d << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c >= f)
		std::cout << c  << " is superior or equal to " << f << std::endl;
	else
		std::cout << c  << " is not superior or equal to " << f << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c >= d)
		std::cout << c  << " is superior or equal to " << d << std::endl;
	else
		std::cout << c  << " is not superior or equal to " << d << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c <= f)
		std::cout << c  << " is inferior or equal to " << f << std::endl;
	else
		std::cout << c  << " is not inferior or equal to " << f << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (c <= d)
		std::cout << c  << " is inferior or equal to " << d << std::endl;
	else
		std::cout << c  << " is not inferior or equal to " << d << std::endl;
	// testing -- operators (c-- vs --c)
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "c = " << c << std::endl;
	--c;
	++c;
	std::cout << "c = " << c << " [should have the same output]" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << c--  << " [should have the same output]" << std::endl;
	std::cout << --c << " [output should be a little lower]" << std::endl;
 
	return 0;
}
