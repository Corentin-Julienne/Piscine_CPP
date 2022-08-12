/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:12 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 16:00:38 by cjulienn         ###   ########.fr       */
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
	delete j;//should not create a leak
	delete i;
	
	// add more tests
	Animal* animal_arr[8];
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
			animal_arr[i] = new Dog();
		else
			animal_arr[i] = new Cat();
	}

	delete[] animal_arr;
	system("leaks Brain");
	return 0;
}