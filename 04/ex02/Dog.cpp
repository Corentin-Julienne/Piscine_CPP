/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:11:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:54:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
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
	this->_brain = new Brain(*original._brain);
	std::cout << "Dog Copy Constructor has been called on " << this->_type << std::endl;
}

Dog&	Dog::operator=(const Dog& original)
{
	if (this != &original)
	{
		this->_type = original._type;
		this->_brain = new Brain(*original._brain);
	}
	std::cout << "Dog: Operator = has been called on " << this->_type << std::endl;
	return *this;
}

std::string		Dog::getIdeaInBrain(int index) const
{
	return (this->_brain->getIdea(index));
}

void			Dog::setIdeaInBrain(int index)
{
	this->_brain->setIdea(index);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf !" << std::endl;
}
