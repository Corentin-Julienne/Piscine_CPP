/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:00 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/16 12:06:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CoplienForm

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(char *file_path) 
{
	this->_openFiles(file_path);
	this->_extractDatabase();
	if (!this->_checkInputValidity()) // check validity and store if valid
		throw std::runtime_error("Error: input file is in wrong format");
	
}

BitcoinExchange::~BitcoinExchange()
{
	// close the file
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
// {
// 	// this->_csv_file = other._csv_file;
// 	// this->_input_file = other._input_file;
// 	// this->_csv_str = other._csv_str;
// 	// this->_input_str = other._input_str;
// 	// this->_db_values = other._db_values;
// 	// this->_input_values = other._input_values;
// }

// BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
// {
// 	if (this != &other)
// 	{
// 		// this->_csv_file = other._csv_file;
// 		// this->_input_file = other._input_file;
// 		// this->_csv_str = other._csv_str;
// 		// this->_input_str = other._input_str;
// 		// this->_db_values = other._db_values;
// 		// this->_input_values = other._input_values;
// 	}
// 	return *this;
// }


/* GETTERS AND SETTERS */

// private helper functions

/* open input file and database */
void	BitcoinExchange::_openFiles(char *file_path) // to test
{	
	this->_input_file.open(file_path, std::ios_base::in);
	if (!this->_input_file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::stringstream		input_buffer;

	input_buffer << this->_input_file.rdbuf();
	this->_input_str = input_buffer.str();

	std::string			database_path = "./data.csv";
	std::stringstream	db_buffer;
	
	this->_csv_file.open(database_path, std::ios_base::in);
	if (!this->_csv_file.is_open())
		throw std::runtime_error("Error: could not open database.");
	db_buffer << this->_csv_file.rdbuf();
	this->_csv_str = db_buffer.str();
}

/* check whether the input file match the following requisites :
=>  Each line in this file must use the following format: "date | value"
=>	A valid date will always be in the following format: Year-Month-Day
=>	A valid value must be either a float or a positive integer between 0 and 1000
 */
bool	BitcoinExchange::_checkInputValidity(void) // to test
{
	std::size_t		pos;
	std::string		token;
	std::string		delimiter = "\n";
	std::string		input_cpy = this->_input_str;
	std::string		time_part;
	std::string		float_part;

	while ((pos = input_cpy.find(delimiter)) != std::string::npos)
	{
		token = input_cpy.substr(0, pos);
		if (token.find("|") == std::string::npos)
			return (false);
		std::cout << "token = |" << token << "|" << std::endl;
		time_part = this->_trimWhitespaces(token.substr(0, token.find("|")));
		float_part = this->_trimWhitespaces(token.substr(token.find("|") + 1));
		if (!this->_checkDateFormatValidity(time_part) || !this->_checkFloatFormatValidity(float_part))
			return (false);
		this->_input_values.insert(std::pair<std::string, std::string>(time_part, float_part));
		input_cpy.erase(0, pos + delimiter.length());
	}
	return (true);
}

/* input : trimmed str than contains a float or an integer with positive value
Check this, returns true if it is the case, false otherwise */
bool	BitcoinExchange::_checkFloatFormatValidity(std::string float_part) // to test
{
	std::cout << "float_part to verify format = |" << float_part << "|" << std::endl;
	
	if (float_part.size() < 1)
		return (false);
	if (float_part.find_first_of('.') == std::string::npos) // case probably an int
	{		
		if (float_part.size() > 4)
			return (false);
		for (std::size_t i = 0; i < float_part.size(); i++)
		{
			if (!std::isdigit(float_part[i]))
				return (false);
		}
		if (atoi(float_part.c_str()) > 1000)
			return (false);
		return (true);
	}
	
	std::string		decimal_part;
	std::string		int_part;

	// for the int part of the float
	int_part = float_part.find_first_of('.');
	if (int_part.size() > 4 || int_part.size() == 0)
		return (false);
	for (std::size_t i = 0; i < int_part.size(); i++)
	{
		if (!std::isdigit(int_part[i]))
			return (false);
	}
	if (atoi(int_part.c_str()) > 1000)
		return (false);
	// for the decimal part of the float
	decimal_part = float_part.substr(float_part.find_first_of('.') + 1);
	std::cout << "decimal part = |" << decimal_part << "|" << std::endl;
	if (decimal_part.size() > 7 && decimal_part.size() == 0)
		return (false);
	for (std::size_t i = 0; i < decimal_part.size(); i++)
	{
		if (!std::isdigit(decimal_part[i]))
			return (false);
	}
	if (atoi(decimal_part.c_str()) > 8388607) // limit for the mantissa in float (23 bits)
		return (false);
	return (true);
}

/* input : trimmed str that should contains a Year-Month-Day format.
Check this, returns true if it is the case, false otherwise */
bool	BitcoinExchange::_checkDateFormatValidity(std::string time_part) // to test
{
	std::cout << "time part to verify format = |" << time_part << "|" << std::endl;
	
	std::string		year;
	std::string		month;
	std::string		day;

	// check general format
	if (time_part.size() != 10 || time_part[4] != '-' || time_part[7] != '-')
		return (false);
	// verifying year
	year = time_part.substr(0, 4);
	std::cout << "year = |" << year << "|" << std::endl;
	for (std::size_t i = 0; i < year.size(); i++)
	{
		if (!std::isdigit(year[i]))
			return (false);
	}
	if (atoi(year.c_str()) < 2011)
		return (false);
	// verifying month
	month = time_part.substr(5, 2);
	std::cout << "month = |" << month << "|" << std::endl;
	for (std::size_t i = 0; i < month.size(); i++)
	{
		if (!std::isdigit(month[i]))
			return (false);
	}
	if (month[0] != '0' && atoi(month.c_str()) > 12)
		return (false);
	// verifying day
	day = time_part.substr(8);
	std::cout << "day = |" << day << "|" << std::endl;
	for (std::size_t i = 0; i < day.size(); i++)
	{
		if (!std::isdigit(day[i]))
			return (false);
	}
	if (day[0] != '0' && atoi(day.c_str()) > 31)
		return (false);
	return (true);
}

void	BitcoinExchange::_extractDatabase(void) // to test
{
	std::size_t			pos;
	std::size_t			iter = 0;
	std::string			token;
	std::string			delimiter = "\n";
	std::string			key;
	std::string			val;

	while ((pos = this->_csv_str.find(delimiter)) != std::string::npos)
	{
		token = this->_csv_str.substr(0, pos);
		if (iter)
		{
			key = token.substr(0, token.find_first_of(','));
			val = token.substr(token.find_first_of(',') + 1);
			this->_db_values.insert(std::pair<std::string, std::string>(key, val));
		}
		this->_csv_str.erase(0, pos + delimiter.length());
		iter++;
	}
}

/* UTILS */

std::string	BitcoinExchange::_trimWhitespaces(std::string str)
{
	std::string		trimmed_str = str;
	
	while (trimmed_str.size() > 0 && std::isspace(trimmed_str.front()))
		trimmed_str = trimmed_str.substr(1);
	while (trimmed_str.size() > 0 && std::isspace(trimmed_str.back()))
		trimmed_str = trimmed_str.substr(0, trimmed_str.size() - 1);
	return (trimmed_str);
}

/* float_str should be available for conversion (i.e. no numeric values or out-of-limits or else) */
float	BitcoinExchange::_strToFloat(std::string float_str)
{
	float			res;
	double			process_conv;

	process_conv = strtod(float_str.c_str(), NULL);
	res = static_cast<float>(process_conv);
	return (res);
}

/* should return the nearest date to then apply conversion */
std::string	BitcoinExchange::_getNearestDate(const std::string date)
{
	std::map<std::string, std::string>::iterator	it_beg = this->_db_values.begin();
	std::map<std::string, std::string>::iterator	it_end = this->_db_values.end();

	// case the exact date exists
	while (it_beg != it_end)
	{
		if (!date.compare(it_beg->first))
			return (it_beg->first);
		it_beg++;
	}
	// case the exact date does not exists
	std::map<std::string, long long int>	diff_map;
	
	it_beg = this->_db_values.begin();
	while (it_beg != it_end)
	{
		
		it_beg++;
	}
}
