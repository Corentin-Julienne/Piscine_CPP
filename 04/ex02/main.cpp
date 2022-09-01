/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:45:10 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/31 17:47:31 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << std::endl;

	delete j;//should not create a leak
	delete i;
	std::cout << std::endl << std::endl;
	system("leaks VirtualAnimal");

	// // ------------------------------------- //
	// std::cout << std::endl << std::endl;
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Test Battery Provided by the Student" << std::endl;
	// std::cout << "------------------------------------" << std::endl;

	// Animal* animal_arr[8];

	// for (int i = 0; i < 8; i++)
	// {
	// 	if (i % 2 == 0)
	// 		animal_arr[i] = new Dog();
	// 	else
	// 		animal_arr[i] = new Cat();
	// }
	// system("leaks VirtualAnimal"); // leak checker
	return 0;
}
