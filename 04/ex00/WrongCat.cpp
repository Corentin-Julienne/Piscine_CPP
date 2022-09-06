/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:29:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:57:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor has been called !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor has been called !" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal(original)
{
	std::cout << "WrongCat Copy Constructor has been called !" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& original)
{
	if (this != &original)
		this->_type = original._type;
	return *this;
}

// class functions (using masking)

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongMiaou !" << std::endl;
}
