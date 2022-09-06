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

// functions

Base * generate(void)
{
	Base	*res;
	int		randomizer;

	randomizer = (rand() % 3) + 1;
	switch (randomizer)
	{
		case 1:
			res = new A();
			break;
		case 2:
			res = new B();
			break;
		case 3:
			res = new C();
			break;
		default:
			break;
	}
	return res;
}

void identify(Base* p)
{
	
	
}

void identify(Base& p)
{
	
}

// main file [tests]

int main(void)
{
	return (0);
}
