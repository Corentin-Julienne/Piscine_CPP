/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:02 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/21 15:19:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>

#include "Date.hpp"

#define TYPE_FLOAT		1
#define TYPE_INT		2

class BitcoinExchange
{
	public:
	
		BitcoinExchange(char *file_path);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		const std::string&	getDatabaseDate(void) const;
		const std::string&	getInputDate(void) const;

		// debug functions
		void	displayDatabase(void);
		void	displayInputFile(void);
		
	private:

		// to enforce Coplien form. Not to be used, so going private !!!
		BitcoinExchange(void);
		// private helper functions
		void			_openFiles(char *file_path);
		void			_extractDatabase(void);
		void			_printContent(void);
		int				_checkNumericFormatValidity(std::string num_part);
		int				_checkFloatValidity(std::string num_part);

		std::string		_computeConversion(float num, const Date date);
		std::string		_computeConversion(int num, const Date date);

		const Date		_getNearestDate(const Date date);
		float			_getConversionRate(const Date date);
		
		// utils
		std::string 	_trimWhitespaces(std::string str);
		float			_strToFloat(std::string float_str);
		
		// data structures and values to store the database
		std::string							_csv_str;
		std::string							_input_str;
		std::map<Date, std::string>			_db_values;
};

#endif
