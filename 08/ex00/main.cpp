/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:57:35 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 11:03:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>

// testing procedure

int main(void)
{
	int					random_num;
	int					choose_a_num;
	int					mirror[10];
	std::vector<int>	vec_test;
	std::deque<int>		deq_test;

	srand(time(NULL)); // ensure soft produce different random num each time
	
	// pushing back some values in vector
	std::cout << "procedure to try to apply easyfind to a vector" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		random_num = rand() % 100;
		vec_test.push_back(random_num);
		mirror[i] = random_num;
		std::cout << "vector index " << i << " is " << random_num << std::endl;	
	}
	std::cout << "----------------------------------------------" << std::endl;
	// try to check if the adequate number is returned 
	try
	{
		choose_a_num = mirror[rand() % 10];
		std::cout << "Num chosen is : " << choose_a_num << std::endl;
		std::vector<int>::iterator it = easyfind(vec_test, choose_a_num);
		std::cout << "Returned number is : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	// check with wrong number (should trigger exception)
	try
	{
		choose_a_num = 104;
		std::cout << "Num chosen is : " << choose_a_num << std::endl;
		std::vector<int>::iterator it = easyfind(vec_test, choose_a_num);
		std::cout << "Returned number is : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "procedure to try to apply easyfind to a deque" << std::endl;
	// pushing back some value in deque
	std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		random_num = rand() % 100;
		deq_test.push_back(random_num);
		mirror[i] = random_num;
		std::cout << "deque index " << i << " is " << random_num << std::endl;	
	}
	std::cout << "----------------------------------------------" << std::endl;
	// try to check if the adequate number is returned 
	try
	{
		choose_a_num = mirror[rand() % 10];
		std::cout << "Num chosen is : " << choose_a_num << std::endl;
		std::deque<int>::iterator it = easyfind(deq_test, choose_a_num);
		std::cout << "Returned number is : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	// check with wrong number (should trigger exception)
	try
	{
		choose_a_num = 104;
		std::cout << "Num chosen is : " << choose_a_num << std::endl;
		std::deque<int>::iterator it = easyfind(deq_test, choose_a_num);
		std::cout << "Returned number is : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
