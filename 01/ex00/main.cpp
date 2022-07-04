/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:33:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie		*heap;
	
	std::cout << "tests with zombie on the stack" << std::endl;
	randomChump("Tim");
	std::cout << "test with zombie on the heap" << std::endl;
	heap = newZombie("Marcus");
	heap->announce();
	delete heap;
	return (0);
}
