/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:38:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/27 15:37:33 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>

class Converter
{
	public:
	
		Converter(void);
		Converter(std::string);
		~Converter();
		Converter(const Converter& original);
		
		Converter&	operator=(const Converter& original);
		
		// check what type it is

		int		is_char(void);
		int		is_int(void);
		int		is_float(void);
		int 	is_double(void);
		int		is_specval(void);

		// print the result

		void	char_printer(void);
		void	int_printer(void);
		void	float_printer(void);
		void	double_printer(void);
		void	specval_printer(void);
		void	inval_printer(void);

		// control tower
	
		void	check_type(void);		
		
	private:
		
		std::string		_input;
};

#endif
