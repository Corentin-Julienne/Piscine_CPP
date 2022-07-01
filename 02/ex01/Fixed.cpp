/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 12:50:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0) 
{
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(int num)
{
	this->_fixed_point = num << _frac_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;	
}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
	std::cout << "Copy constructor called" << std::endl;
}

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

Fixed&	Fixed::operator=(const Fixed& ref)
{
	if (this != &ref)
		this->_fixed_point = ref.getRawBits();
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

int	Fixed::toInt(void) const
{
	int		res;
	
	res = 
}

float	Fixed::toFloat(void) const
{
	float	res;

	

	return (res);
}

// out of the class

std::ostream&	operator<<(std::ostream &flux, const Fixed& ref)
{
	flux << ref.toFloat();
	return (flux);
}
