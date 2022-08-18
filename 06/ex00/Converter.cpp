/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/18 16:37:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void) : _input("Test")
{
	// check the type of string litteral stored in this->_input
	if (this->_input.empty())
		; // raise a type of error
	else if (this->_input.size() == 1)
		this->oneChar(); // check when only a char
	else
		this->severalChar(); // check type when str is more than one char
	// then assign and convert
	switch (this->_type)
	{
		case charType:
			this->convertChar();
			break;
		
		case intType:
			this->convertInt();
			break;

		case floatType:
			this->convertFloat();
			break;
		
		case doubleType:
			this->convertDouble();
			break;
		
		default:
			break;
	}
}

Converter::Converter(std::string input) : _input(input)
{
	// check the type of string litteral stored in this->_input
	if (this->_input.empty())
		; // raise a type of error
	else if (this->_input.size() == 1)
		this->oneChar(); // check when only a char
	else
		this->severalChar(); // check type when str is more than one char
	// then assign and convert
	switch (this->_type)
	{
		case charType:
			this->convertChar();
			break;
		
		case intType:
			this->convertInt();
			break;

		case floatType:
			this->convertFloat();
			break;
		
		case doubleType:
			this->convertDouble();
			break;
		
		default:
			break;
	}
}

Converter::~Converter() {}

Converter::Converter(const Converter& original) : _input(original._input), _char(original._char),
_int(original._int), _float(original._float), _double(original._double), _type(original._type)
{}

Converter&	Converter::operator=(const Converter& original)
{
	if (this != &original)
	{
		_input = original._input;
		_char = original._char;
		_int = original._int;
		_float = original._float;
		_double = original._double;
		_type = original._type;
	}
	return *this;
}

// check type functions

void	Converter::oneChar(void)
{
	if (this->_input.front() >= 48 && this->_input.front() <= 58)
		this->_type = intType;
	else
		this->_type = charType;	
}

void	Converter::severalChar(void)
{
	// check for pseudo floats litterals
	if (!this->_input.compare("-inff") || !this->_input.compare("+inff") || !this->_input.compare("nanf"))
		this->_type = floatType;
	// check for pseudo double litterals
	else if (!this->_input.compare("-inf") || !this->_input.compare("+inf") || !this->_input.compare("nan"))
		this->_type = doubleType;
	else
	{
		// to implement
	}
}

// conversion functions

void	Converter::convertChar(void)
{
	this->_char = this->_input.front();
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void	Converter::convertInt(void)
{
	char	*p_end;
	
	this->_int = strtol(this->_input.c_str(), &p_end, 10); // pb there ?
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void	Converter::convertFloat(void)
{
	char	*p_end;

	this->_float = strtof(this->_input.c_str(), &p_end);
	this->_char = static_cast<char>(this->_float);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<float>(this->_float);
}

void	Converter::convertDouble(void)
{
	char	*p_end;

	this->_double = strtod(this->_input.c_str(), &p_end);
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
}

// check if printable

char	Converter::printChar(void) const
{
	if (!isprint(this->_char))
		; // throw exception
	else
		return (this->_char);
}

int		Converter::printInt(void) const
{
	return (this->_int);
}

float	Converter::printFloat(void) const
{
	return (this->_float);
}

double	Converter::printDouble(void) const
{
	return (this->_double);	
}

// exceptions handling

const char* Converter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char* Converter::WrongInputException::what() const throw()
{
	return ("Wrong input");
}

const char* Converter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

// overloading operator <<

std::ostream&	operator<<(std::ostream& stream, const Converter& converter)
{
	stream << "char: ";
	try {
		stream << converter.printChar() << std::endl;
	} catch (std::exception & e) {
		stream << e.what() << std::endl;
	}
	stream << "int: ";
	try {
		stream << converter.printInt() << std::endl;
	} catch (std::exception & e) {
		stream << e.what() << std::endl;		
	}
	stream << "float: ";
	try {
		stream << converter.printFloat() << std::endl;
	} catch (std::exception & e) {
		stream << e.what() << std::endl;
	}
	stream << "double: ";
	try {
		stream << converter.printDouble() << std::endl;
	} catch (std::exception & e) {
		stream << e.what() << std::endl;
	}
	return (stream);
}
