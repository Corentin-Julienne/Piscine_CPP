/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 15:21:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog Constructor has been called on " << this->_type << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor has been called on " << this->_type << std::endl;
}

Dog::Dog(const Dog& original)
{
	this->_type = original._type;
	this->_brain = new Brain();
	std::cout << "Dog Copy Constructor has been called on " << this->_type << std::endl;
}

Dog&	Dog::operator=(const Dog& original)
{
	if (this != &original)
	{
		this->_type = original._type;
		this->_brain = new Brain();
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf !" << std::endl;
}
