/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/27 15:48:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void) {}

Converter::Converter(std::string input) : _input(input) {}

Converter::~Converter() {}

Converter::Converter(const Converter& original) : _input(original._input) {}

Converter&	Converter::operator=(const Converter& original)
{
	if (this != &original)
		_input = original._input;
	return *this;
}

// check types

int	Converter::is_char(void)
{	
	if (this->_input.size() != 1)
		return (0);
	
	int n = (int)this->_input[0];

	if (n >= 32 && n <= 126)
		return (1);
	return (0);
}

int	Converter::is_int(void)
{
	if (this->_input[0] != '-' && (this->_input[0] < '0' || this->_input[0] > '9'))
		return (1);
	for (int i = 1; i < this->_input.size(); i++)
	{
		if (this->_input[0] < '0' || this->_input[0] > '9')
			return (1);
	}
	return (0);
}

int	Converter::is_float(void)
{
	// check if there is the 'f' at the end of the string
	if (this->_input[this->_input.size() - 1] != 'f')
		return (1);
	// check for the presence of a single dot in the string and all other char are numbers
	// (excluding the last one and the first in case it is the - sign)
	if (this->_input[0] != '-' && ((this->_input[0] < '0' || this->_input[0] > '9')))
		return (1);
	int		num_of_dots = 0;
	for (int i = 1; i < this->_input.size() - 1; i++)
	{
		if ((this->_input[i] < '0' || this->_input[i] > '9') && this->_input[i] != '.')
			return (1);
		if (this->_input[i] == '.')
			num_of_dots++;
	}
	if (num_of_dots != 1 || this->_input[this->_input.size() - 2] == '.')
		return (1);
	return (0);
}

int	Converter::is_double(void)
{
	// check for the presence of a single dot in the string and all other char are numbers
	// (excluding the last one and the first in case it is the - sign)
	if (this->_input[0] != '-' && ((this->_input[0] < '0' || this->_input[0] > '9')))
		return (1);
	int		num_of_dots = 0;
	for (int i = 1; i < this->_input.size(); i++)
	{
		if ((this->_input[i] < '0' || this->_input[i] > '9') && this->_input[i] != '.')
			return (1);
		if (this->_input[i] == '.')
			num_of_dots++;
	}
	if (num_of_dots != 1 || this->_input[this->_input.size() - 1] == '.')
		return (1);
	return (0);
}

int	Converter::is_specval(void)
{
	if (!this->_input.compare("nan") || !this->_input.compare("nanf") || !this->_input.compare("+inf")
	|| !this->_input.compare("-inf") || !this->_input.compare("+inff") || !this->_input.compare("-inff"))
		return (1);
	return (0);
}

// print functions 

void	Converter::char_printer(void)
{
	
}

void	Converter::int_printer(void)
{

}

void	Converter::float_printer(void)
{
	
}

void	Converter::double_printer(void)
{

}

void	Converter::specval_printer(void)
{

}

void	Converter::inval_printer(void)
{
	
}

// check if string is convertible in char, double, float or int

void	Converter::check_type(void)
{
	if (this->is_char() == 1)
		this->char_printer();
	else if (this->is_int() == 1)
		this->int_printer();
	else if (this->is_float() == 1)
		this->float_printer();
	else if (this->is_double() == 1)
		this->double_printer();
	else if (this->is_specval() == 1)
		this->specval_printer();
	else
		this->inval_printer();
}
