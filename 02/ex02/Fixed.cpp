/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:11 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/30 18:03:41 by cjulienn         ###   ########.fr       */
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

// min AND max functions

Fixed&			Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed&			Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

// overloading arithmetic operators

Fixed	Fixed::operator+(const Fixed &scd)
{
	Fixed		res;

	res.setRawBits(this->_fixedPoint + scd.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &scd)
{
	Fixed		res;

	res.setRawBits(this->_fixedPoint - scd.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &scd)
{
	Fixed		res;

	res.setRawBits(this->_fixedPoint * scd.getRawBits() >> this->_fracBits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &scd)
{
	Fixed		res;

	res.setRawBits((this->_fixedPoint * (1 << this->_fracBits)) / scd.getRawBits());
	return (res);
}

// overloading increment/decrement operators

Fixed	Fixed::operator++(void)
{
	this->_fixedPoint += 1;
	return *this;
}

Fixed	Fixed::operator--(void)
{
	this->_fixedPoint -= 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(this->toFloat());
	
	this->_fixedPoint += 1;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(this->toFloat());
	
	this->_fixedPoint -= 1;
	return tmp;
}

// overloading comparison operators

bool			Fixed::operator==(const Fixed &scd)
{
	if (this->toFloat() == scd.toFloat())
		return (true);
	return (false);
}

bool			Fixed::operator!=(const Fixed &scd)
{
	if (this->toFloat() != scd.toFloat())
		return (true);
	return (false);
}

bool			Fixed::operator<(const Fixed &scd)
{
	if (this->toFloat() < scd.toFloat())
		return (true);
	return (false);
}

bool			Fixed::operator>(const Fixed &scd)
{
	if (this->toFloat() > scd.toFloat())
		return (true);
	return (false);
}

bool			Fixed::operator<=(const Fixed &scd)
{
	if (this->toFloat() <= scd.toFloat())
		return (true);
	return (false);
}

bool			Fixed::operator>=(const Fixed &scd)
{
	if (this->toFloat() >= scd.toFloat())
		return (true);
	return (false);
}

// overload operator <<

std::ostream&	operator<<(std::ostream &flux, const Fixed& ref)
{
	flux << ref.toFloat();
	return (flux);
}
