/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:02 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/15 17:22:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>

#include <unistd.h> // for usleep/debug purpose only

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
		void	_openFiles(char *file_path);
		void	_extractDatabase(void);
		bool	_checkInputValidity(void);
		bool	_checkDateFormatValidity(std::string time_part);
		bool	_checkFloatFormatValidity(std::string float_part);

		std::string	_getNearestDate(const std::string date);
		
		// utils
		std::string 	_trimWhitespaces(std::string str);
		float			_strToFloat(std::string float_str);
		
		// data structures and values to store the database
		std::ifstream						_csv_file;
		std::ifstream						_input_file;
		std::string							_csv_str;
		std::string							_input_str;
		std::map<std::string, std::string>	_db_values;
		std::map<std::string, std::string>	_input_values;
};

#endif
