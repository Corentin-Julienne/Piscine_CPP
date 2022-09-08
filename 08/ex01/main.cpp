/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:29:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 15:39:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

int main(void)
{
	Span sp = Span(5);
	// should trigger exceptions
	std::cout << "Try to retrieve longuest and shortest span of an empty Span [should trigger exceptions]" << std::endl;
	try
	{
		std::cout << "Trying ot retrieve longuest span : " << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Trying ot retrieve shortest span : " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	// population span vector
	std::cout << "Testing the function to add numbers in Span one by one" << std::endl;
	try
	{
		sp.addNumber(6);  // index 0
		sp.addNumber(3);  // index 1
		sp.addNumber(17); // index 2
		sp.addNumber(9);  // index 3
		sp.addNumber(11); // index 4
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "num in Span at index 4 is " << sp.getByIndex(4); // should output 11
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "num in Span at index 5 is " << sp.getByIndex(5); // should trigger exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "trying to use shortest and longuest span with the new Span" << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	// testing addSeveralNumbers method
	std::cout << "testing with method to add several numbers to Span at once" << std::endl;

	std::vector<int>	new_vect;
	new_vect.push_back(37);     // index 5
	new_vect.push_back(44);  	// index 6
	new_vect.push_back(4562);   // index 7
	std::cout << "trying to add several num at once with full Span [should trigger exception]" << std::endl;
	try
	{
		sp.addSeveralNumbers(new_vect.begin(), new_vect.end()); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	
	// testing with more than 10.000 values

	srand(time(NULL)); // seed for random numbers generation

	std::cout << "Testing within a huge number of values (more than 10.000)" << std::endl << std::endl;

	std::vector<int>huge_vect;
	Span	huge_span(10500);

	for (int i = 0; i < 10500; i++)
		huge_vect.push_back(rand() % 100);
	std::cout << "check if add several numbers at one trigger an exception" << std::endl;
	try
	{
		huge_span.addSeveralNumbers(huge_vect.begin(), huge_vect.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "retrieve some numbers randomly (10) to check if we can access it (should work)" << std::endl;
	try
	{
		size_t		index;
		
		for (int i = 0; i < 10; i++)
		{
			index = rand() % 10500;

			std::cout << "Span of index " << index << " have the value " << huge_span.getByIndex(index) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "sorting longuest and shortest span for the huge Spa" << std::endl;
	std::cout << "Longest span is " << huge_span.longestSpan() << std::endl;
	std::cout << "Shortest span is " << huge_span.shortestSpan() << std::endl;
	return (0);
}
