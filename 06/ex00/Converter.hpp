/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/05 15:50:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>
#include <exception>
#include <iomanip>
#include <math.h>


#include <stdlib.h>

/* The Converter object/class first check what type of litteral is actually represented by the string :
!!! 3 is considered ant int litteral, not a char litteral
(instructions implies implicitely that litteral should be of one type only) 

the << operator is overloaded to display the output in a good format
*/

class Converter
{
	public:
	
		Converter(void);
		Converter(std::string);
		~Converter();
		Converter(const Converter& original);
		
		Converter&	operator=(const Converter& original);
		
		// check what type it is

		void	oneChar(void);
		void	severalChar(void);

		// convert str to every type

		char	convertToChar(void);
		int		convertToInt(void);
		float	convertToFloat(void);
		double	convertToDouble(void);
		
		// exception classes

		class NonDisplayableException : public std::exception 
		{
			public:

				const char* what() const throw();
		};

		class WrongInputException : public std::exception
		{
			public:

				const char* what() const throw();
		};

		class ImpossibleException : public std::exception
		{
			public:

				const char* what() const throw();
		};

		class EmptyStringException : public std::exception
		{
			public:

				const char* what() const throw();	
		};

	private:
		
		std::string			_input;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
		
		enum litteralType {
			charType,
			intType,
			floatType,
			doubleType,
			invalType
		} 					_type;
};

// overloadind operator <<

std::ostream&	operator<<(std::ostream& stream, Converter& converter);

#endif
