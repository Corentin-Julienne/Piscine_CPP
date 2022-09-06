/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:56:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog Constructor has been called on " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor has been called on " << this->_type << std::endl;
}

Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Dog Copy Constructor has been called on " << this->_type << std::endl;
}

Dog&	Dog::operator=(const Dog& original)
{
	std::cout << "Dog: Operator = has been called on " << this->_type << std::endl;
	if (this != &original)
		this->_type = original._type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf !" << std::endl;
}
