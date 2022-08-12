/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 12:17:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// basic constructor

WrongAnimal::WrongAnimal(void)
{
	this->_type = "Nothing";
	std::cout << "WrongAnimal Constructor has been called on " << this->_type << std::endl;
}

// constructor with name

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Wrong Animal Constructor has been called on " << this->_type << std::endl;
}

// destructor

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor has been called on " << this->_type << std::endl;
}

// constructor by copy

WrongAnimal::WrongAnimal(const WrongAnimal& original) : _type(original._type)
{
	std::cout << "WrongAnimal Constructor by Copy has been called on " << this->_type << std::endl;
}

// overloading operator =

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& original)
{
	if (this != &original)
		this->_type = original._type;
	return *this;
}

// getters and setters

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// class functions

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal as a concept does not produce any sound you dumb f***!!!" << std::endl;
}
