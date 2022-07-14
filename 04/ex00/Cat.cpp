/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:45 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/14 16:24:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") 
{
	std::cout << "Cat Constructor has been called !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor has been called !" << std::endl;
}

Cat::Cat(const Cat& original)
{
	this->type = original.type;
	std::cout << "Cat Copy Constructor has been called !" << std::endl;
}

Cat&	Cat::operator=(const Cat& original)
{
	if (this != &original)
		this->type = original.type;
	return *this;
}

// class functions (using masking)

void	Cat::makeSound(void)
{
	std::cout << "Miaou !" << std::endl;
}
