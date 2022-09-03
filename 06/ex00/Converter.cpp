/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 16:24:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void) : _input("Test")
{
	if (this->_input.empty())
		throw EmptyStringException(); 
	else if (this->_input.size() == 1)
		this->oneChar();
	else
		this->severalChar();
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
	if (this->_input.empty())
		throw EmptyStringException(); 
	if (this->_input.size() == 1)
		this->oneChar();
	else
		this->severalChar();
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
_int(original._int), _float(original._float), _double(original._double), _type(original._type) {}

Converter&	Converter::operator=(const Converter& original)
{
	if (this != &original)
	{
		this->_input = original._input;
		this->_char = original._char;
		this->_int = original._int;
		this->_float = original._float;
		this->_double = original._double;
		this->_type = original._type;
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
	if (!this->_input.compare("-inff") || !this->_input.compare("+inff") || !this->_input.compare("nanf"))
		this->_type = floatType;
	else if (!this->_input.compare("-inf") || !this->_input.compare("+inf") || !this->_input.compare("nan"))
		this->_type = doubleType;
	else
	{
		// check for int
		char			*checker_int;
		long long int	int_res = strtol(this->_input.c_str(), &checker_int, 10);
		if (!*checker_int)
		{
			if (int_res < std::numeric_limits<int>::min() || int_res > std::numeric_limits<int>::max())
				throw WrongInputException();
			this->_type = intType;
			return ;
		}
		// check for float and doubles
		char				*checker_float;
		double				float_res = strtod(this->_input.c_str(), &checker_float);
		std::ostringstream	convert_to_str;
		convert_to_str << float_res;
	
		if (!*checker_float)
		{
			if (float_res == std::numeric_limits<double>::min() && this->_input.compare(convert_to_str.str()))
				throw WrongInputException();
			if (float_res == std::numeric_limits<double>::max() && this->_input.compare(convert_to_str.str()))
				throw WrongInputException();
			this->_type = doubleType;
			return ;
		}
		else if (*checker_float)
		{
			std::string		suffix(checker_float);
			
			if (float_res == std::numeric_limits<float>::min() && this->_input.compare(convert_to_str.str()))
				throw WrongInputException();
			if (float_res == std::numeric_limits<float>::max() && this->_input.compare(convert_to_str.str()))
				throw WrongInputException();
			if (suffix.size() == 1 && (suffix.back() == 'f' || suffix.back() == 'F'))	
				this->_type = floatType;
			else
				throw WrongInputException();
		}
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
	this->_int = strtol(this->_input.c_str(), NULL, 10);
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void	Converter::convertFloat(void)
{
	this->_float = strtof(this->_input.c_str(), NULL);
	this->_char = static_cast<char>(this->_float);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<float>(this->_float);
}

void	Converter::convertDouble(void)
{
	this->_double = strtod(this->_input.c_str(), NULL);
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
}

char	Converter::printChar(void) const
{
	if (!isprint(this->_char))
		throw NonDisplayableException();
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

const char* Converter::EmptyStringException::what() const throw()
{
	return ("empty string");
}

// overloading operator <<

std::ostream&	operator<<(std::ostream& stream, const Converter& converter)
{
	stream << "char: ";
	try {
		stream << converter.printChar();
		stream << "'" << std::endl;
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
