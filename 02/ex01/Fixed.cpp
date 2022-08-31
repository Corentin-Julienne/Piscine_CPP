/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/30 11:44:12 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// basic constructor

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// int and  float constructors

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = num << this->_fracBits;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (int)roundf(num * (1 << this->_fracBits));
}

// destructor

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// constructor by copy

Fixed::Fixed(const Fixed& original)
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

// conversion functions

int	Fixed::toInt(void) const
{
	int		res;

	res = this->_fixedPoint >> this->_fracBits;
	return (res);
}

float	Fixed::toFloat(void) const
{
	float	res;

	res = (float)this->_fixedPoint / (1 << this->_fracBits);
	return (res);
}

// overload operator << [OUT OF THE CLASS METHODS !!!]

std::ostream&	operator<<(std::ostream &flux, const Fixed& ref)
{
	flux << ref.toFloat();
	return (flux);
}
