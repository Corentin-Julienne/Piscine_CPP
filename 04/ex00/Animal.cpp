/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:41 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/14 16:33:16 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// basic constructor

Animal::Animal(void)
{
	std::cout << "Animal Constructor has been called !" << std::endl;
}

// constructor with type

Animal::Animal(std::string animal_type) : type(animal_type) 
{
	std::cout << "Animal Constructor has been called !" << std::endl;
}

// destructor

Animal::~Animal()
{
	std::cout << "Animal Destructor has been called !" << std::endl;
}

// constructor by copy

Animal::Animal(const Animal& original)
{
	this->type = original.type;
	std::cout << "Animal Copy Constructor has been called !" << std::endl;
}

// overloading assignement operator

Animal&	Animal::operator=(const Animal& original)
{
	if (this != &original)
		this->type = original.type;
	return *this;
}

// getters and setters

std::string	getType(void)
{
	return (this->type);
}

// class functions

void	makeSound(void)
{
	std::cout << "Animal as a concept does not produce any sound !!!" << std::endl;
}
