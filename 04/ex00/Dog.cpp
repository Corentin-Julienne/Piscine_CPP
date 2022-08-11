/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 17:16:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog Constructor has been called !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor has been called !" << std::endl;
}

Dog::Dog(const Dog& original)
{
	this->_type = original._type;
	std::cout << "Dog Copy Constructor has been called !" << std::endl;
}

Dog&	Dog::operator=(const Dog& original)
{
	if (this != &original)
		this->_type = original._type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf !" << std::endl;
}
