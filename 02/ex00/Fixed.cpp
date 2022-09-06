/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:59 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 10:31:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// basic constructor

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// destructor

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

// constructor by copy

Fixed::Fixed(const Fixed& original) : _fixedPoint(original._fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = original.getRawBits();
}

// overloading assignement operator

Fixed&	Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->_fixedPoint = original.getRawBits();
	return *this;
}

// getters and setters

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}
