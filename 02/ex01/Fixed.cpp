/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/12 18:07:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// basic constructor

Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// int and  float constructors

Fixed::Fixed(int num)
{
	this->_fixed_point = num << _frac_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
}

// destructor

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

// constructor by copy

Fixed::Fixed(const Fixed& original)
{
	_fixed_point = original._fixed_point;
	std::cout << "Copy constructor called" << std::endl;
}

// overloading assignement operator

Fixed&	Fixed::operator=(const Fixed& original)
{
	if (this != &original)
		_fixed_point = original._fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

// getters and setters

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int raw)
{
	this->_fixed_point = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

// conversion functions

int	Fixed::toInt(void) const
{
	int		res;
	
}

float	Fixed::toFloat(void) const
{
	float	res;

	

	return (res);
}

// overload operator << [OUT OF THE CLASS METHODS !!!]

std::ostream&	operator<<(std::ostream &flux, const Fixed& ref)
{
	flux << ref.toFloat();
	return (flux);
}
