/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:45 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:56:42 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat Constructor has been called on " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor has been called on " << this->_type << std::endl;
}

Cat::Cat(const Cat& original) : Animal(original)
{
	std::cout << "Cat Copy Constructor has been called on " << this->_type << std::endl;
}

Cat&	Cat::operator=(const Cat& original)
{
	std::cout << "Cat: Operator = has been called on " << this->_type << std::endl;
	if (this != &original)
		this->_type = original._type;
	return *this;
}

// class functions (using masking)

void	Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}
