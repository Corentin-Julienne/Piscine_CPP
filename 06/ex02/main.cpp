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
	if (dynamic_cast<A*>(p))
		std::cout << "Is type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Is type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Is type C" << std::endl;
	else
		std::cerr << "Error" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	*ptn_1 = NULL;
		
		*ptn_1 = dynamic_cast<A&>(p);
		std::cout << "Is type A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B	*ptn_2 = NULL;
		
		*ptn_2 = dynamic_cast<B&>(p);
		std::cout << "Is type B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C	*ptn_3 = NULL;

		*ptn_3 = dynamic_cast<C&>(p);
		std::cout << "Is type C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cerr << "Error" << std::endl;
}

// main file [tests]

int main(void)
{
	std::cout << "Tests with pointers" << std::endl;

	Base *ptn_example_1 = generate();
	Base *ptn_example_2 = generate();

	identify(ptn_example_1);
	identify(ptn_example_2);

	std::cout << "Tests with references" << std::endl;

	Base *ptn_example_3 = generate();
	Base *ptn_example_4 = generate();

	identify(*ptn_example_3);
	identify(*ptn_example_4);

	// delete stuff

	delete	ptn_example_1;
	delete	ptn_example_2;
	delete	ptn_example_3;
	delete	ptn_example_4;

	//system("leaks Identifier"); // debug only
	return (0);
}
