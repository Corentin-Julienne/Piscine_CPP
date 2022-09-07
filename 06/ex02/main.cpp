/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:28:28 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/05 17:45:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

// functions

Base * generate(void)
{
	Base	*res = NULL;
	int		randomizer;

	srand(time(NULL));
	randomizer = (rand() % 3) + 1;
	switch (randomizer)
	{
		case 1:
			res = new A();
			std::cout << "Randomly chosen : Type A" << std::endl; // for testing prupose and made correction easier
			break;
		case 2:
			res = new B();
			std::cout << "Randomly chosen : Type B" << std::endl; // for testing prupose and made correction easier
			break;
		case 3:
			res = new C();
			std::cout << "Randomly chosen : Type C" << std::endl; // for testing prupose and made correction easier
			break;
		default:
			break; // should never trigger that
	}
	return res;
}

void identify(Base* p)
{
	A	*res_a;
	
	p = dynamic_cast<A*>(res_a);
	if (p == NULL)
		std::cout << "not a type A" << std::endl;
}

/*void identify(Base& p)
{
	
}*/

// main file [tests]

int main(void)
{
	return (0);
}
