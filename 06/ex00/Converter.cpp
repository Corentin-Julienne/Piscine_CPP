/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/05 17:12:03 by cjulienn         ###   ########.fr       */
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
}

Converter::Converter(std::string input) : _input(input)
{
	if (this->_input.empty())
		throw EmptyStringException(); 
	if (this->_input.size() == 1)
		this->oneChar();
	else
		this->severalChar();
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
	if (isdigit(this->_input.front()))
	{
		this->_type = intType;
		this->_int = static_cast<int>(atoi(this->_input.c_str()));
	}
	else
	{
		this->_type = charType;
		this->_char = this->_input.front();
	}
}

void	Converter::severalChar(void)
{
	if (!this->_input.compare("-inff") || !this->_input.compare("+inff") || !this->_input.compare("nanf"))
	{
		float		convert_f = strtof(this->_input.c_str(), NULL);
		
		this->_type = floatType;
		this->_float = convert_f;
	}
	else if (!this->_input.compare("-inf") || !this->_input.compare("+inf") || !this->_input.compare("nan"))
	{
		double		convert_d = strtod(this->_input.c_str(), NULL);
		
		this->_type = doubleType;
		this->_double = convert_d;
	}
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
			this->_int = static_cast<int>(int_res);
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
			this->_double = static_cast<double>(float_res);
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
			{
				this->_type = floatType;
				this->_float = static_cast<float>(float_res);
			}
			else
				throw WrongInputException();
		}
	}
}

// conversion functions

char	Converter::convertToChar(void)
{
	switch (this->_type)
	{
		case intType:
			if (!isprint(static_cast<char>(this->_int)))
				throw NonDisplayableException();
			else
				return (static_cast<char>(this->_int));
		case floatType:
			if (isinf(this->_float) || isnan(this->_float)
				|| this->_float > std::numeric_limits<char>::max()
				|| this->_float < std::numeric_limits<char>::min())
				throw ImpossibleException();
			else if (!isprint(this->_float))
				throw NonDisplayableException();			
			else 
				return (static_cast<char>(this->_float));
		case doubleType:
			if (isinf(this->_double) || isnan(this->_double)
				|| this->_double > std::numeric_limits<char>::max()
				|| this->_double < std::numeric_limits<char>::min())
				throw ImpossibleException();
			else if (!isprint(this->_double))
				throw NonDisplayableException();
			else
				return (static_cast<char>(this->_double));
		default:
			return (this->_char);
	}
}

int		Converter::convertToInt(void)
{
	switch (this->_type)
	{
		case charType:
			return (static_cast<int>(this->_char));
		case floatType:
			if (isinf(this->_float) || isnan(this->_float)
			|| this->_float > std::numeric_limits<int>::max()
			|| this->_float < std::numeric_limits<int>::min())
				throw ImpossibleException();
			else
				return (static_cast<int>(this->_float));
		case doubleType:
			if (isinf(this->_double) || isnan(this->_double)
				|| this->_double > std::numeric_limits<int>::max()
				|| this->_double < std::numeric_limits<int>::min())
				throw ImpossibleException();
			else
				return (static_cast<int>(this->_double));
		default:
			return (this->_int);
	}
}

float	Converter::convertToFloat(void)
{
	switch (this->_type)
	{
		case charType:
			return (static_cast<float>(this->_char));
		case intType:
			return (static_cast<float>(this->_int));
		case doubleType:
			return (static_cast<float>(this->_double));
		default:
			return (this->_float);
	}
}

double	Converter::convertToDouble(void)
{
	switch (this->_type)
	{
		case charType:
			return (static_cast<double>(this->_char));
		case intType:
			return (static_cast<double>(this->_int));
		case floatType:
			return (static_cast<double>(this->_float));
		default:
			return (this->_double);
	}
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

std::ostream&	operator<<(std::ostream& stream, Converter& converter)
{
	stream << "char: ";
	try 
	{
		char c = converter.convertToChar();
		stream << "'" << c << "'" << std::endl;
	} 
	catch (std::exception & e) 
	{
		stream << e.what() << std::endl;
	}
	stream << "int: ";
	try 
	{
		stream << converter.convertToInt() << std::endl;
	}
	catch (std::exception & e) 
	{
		stream << e.what() << std::endl;
	}
	stream << "float: ";
	try
	{
		int		checker = static_cast<int>(converter.convertToFloat());
		float	cpy		= converter.convertToFloat();
		
		stream << converter.convertToFloat();
		if (cpy - checker == 0)
			stream << ".0";
		stream << "f" << std::endl;
	}
	catch (std::exception & e) 
	{
		stream << e.what() << std::endl;
	}
	stream << "double: ";
	try 
	{
		int		checker = static_cast<int>(converter.convertToFloat());
		double	cpy		= converter.convertToFloat();

		stream << converter.convertToDouble();
		if (cpy - checker == 0)
			stream << ".0" << std::endl;
	} 
	catch (std::exception & e) 
	{
		stream << e.what() << std::endl;
	}
	return (stream);
}
