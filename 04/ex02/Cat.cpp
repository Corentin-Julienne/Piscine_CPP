/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:11:00 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/31 15:12:35 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat Constructor has been called !" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor has been called !" << std::endl;
}

Cat::Cat(const Cat& original)
{
	this->_type = original._type;
	this->_brain = new Brain(*original._brain);
	std::cout << "Cat Copy Constructor has been called !" << std::endl;
}

Cat&	Cat::operator=(const Cat& original)
{
	if (this != &original)
	{
		this->_type = original._type;
		this->_brain = new Brain(*original._brain);
	}
	std::cout << "Cat: Operator = has been called on " << this->_type << std::endl;
	return *this;
}

// class functions (using masking)

void	Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}
