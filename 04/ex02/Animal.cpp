/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:10:51 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/31 17:44:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

// basic constructor

Animal::Animal(void)
{
	this->_type = "Animal[concept]";
	std::cout << "Animal Constructor has been called on " << this->_type << std::endl;
}

// constructor with type

Animal::Animal(std::string animal_type) : _type(animal_type) 
{
	std::cout << "Animal Constructor has been called on " << this->_type << std::endl;
}

// destructor

Animal::~Animal()
{
	std::cout << "Animal Destructor has been called on " << this->_type << std::endl;
}

// constructor by copy

Animal::Animal(const Animal& original) : _type(original._type)
{
	std::cout << "Animal Copy Constructor has been called on " << this->_type << std::endl;
}

// overloading assignement operator

Animal&	Animal::operator=(const Animal& original)
{
	std::cout << "Animal: Operator = has been called on " << this->_type << std::endl;
	if (this != &original)
		this->_type = original._type;
	return *this;
}

// getters and setters

std::string	Animal::getType(void) const
{
	return (this->_type);
}
