/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:12 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:56:55 by cjulienn         ###   ########.fr       */
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
	//system("leaks Brain");

	// ------------------------------------- //
	std::cout << std::endl << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Test Battery Provided by the Student" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	// ------------------------------------- //

	Animal* animal_arr[8];

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
			animal_arr[i] = new Dog();
		else
			animal_arr[i] = new Cat();
	}
	
	Dog	cpy(*(Dog *)animal_arr[3]); // deep copy of animal (should be a dog)

	for (int i = 0; i < 100; i++) // know, ideas should be the same
	{
		if (cpy.getIdeaInBrain(i).compare(((Dog *)animal_arr[3])->getIdeaInBrain(i)))
		{
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "indea index " << i << " is " << cpy.getIdeaInBrain(i) << " for the copy"
			<< " and " << ((Dog *)animal_arr[3])->getIdeaInBrain(i) << " for the original" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
		} // should print nothing
	}
	// know we change an idea, for the sake of the exercize
	cpy.setIdeaInBrain(0);
	for (int i = 0; i < 100; i++) // know, ideas should be the same
	{
		if (cpy.getIdeaInBrain(i).compare(((Dog *)animal_arr[3])->getIdeaInBrain(i)))
		{
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "indea index " << i << " is " << cpy.getIdeaInBrain(i) << " for the copy"
			<< " and " << ((Dog *)animal_arr[3])->getIdeaInBrain(i) << " for the original" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
		} // should print somethinf for index 0
	}	
	for (int i = 0; i < 8; i++)
	{
		delete animal_arr[i];
	}
	//system("leaks Brain"); // leak checker
	return 0;
}
