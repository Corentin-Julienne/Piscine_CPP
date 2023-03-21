/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:00 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/21 15:21:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CoplienForm

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(char *file_path) 
{
	this->_openFiles(file_path);
	this->_extractDatabase();
	this->_printContent();
}

BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
// {
// 	// this->_csv_str = other._csv_str;
// 	// this->_input_str = other._input_str;
// 	// this->_db_values = other._db_values;
// 	// this->_input_values = other._input_values;
// }

// BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
// {
// 	if (this != &other)
// 	{
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
	std::ifstream			input_file;
	std::stringstream		input_buffer;
	
	input_file.open(file_path, std::ios_base::in);
	if (!input_file.is_open())
		throw std::runtime_error("Error: could not open file.");
	input_buffer << input_file.rdbuf();
	this->_input_str = input_buffer.str();

	std::ifstream			csv_file;
	std::string				database_path = "./data.csv";
	std::stringstream		db_buffer;
	
	csv_file.open(database_path, std::ios_base::in);
	if (!csv_file.is_open())
		throw std::runtime_error("Error: could not open database.");
	db_buffer << csv_file.rdbuf();
	this->_csv_str = db_buffer.str();

	// close files
	input_file.close();
	csv_file.close();
}

std::string	BitcoinExchange::_computeConversion(float num, const Date date)
{
	std::stringstream	ss;
	float				exchange_rate = this->_getConversionRate(date);

	ss << (num * exchange_rate);
	return (ss.str());
}

std::string	BitcoinExchange::_computeConversion(int num, const Date date)
{
	std::stringstream	ss;
	float				float_num = static_cast<float>(num);
	float				exchange_rate = this->_getConversionRate(date);

	ss << (float_num * exchange_rate);
	return (ss.str());
}

/* try to display */
void	BitcoinExchange::_printContent(void) // to test
{
	std::size_t		pos;
	std::string		token;
	std::string		delimiter = "\n";
	std::string		input_cpy = this->_input_str;
	std::string		date_part;
	std::string		num_part;

	while ((pos = input_cpy.find(delimiter)) != std::string::npos)
	{
		token = input_cpy.substr(0, pos);
		if (token.find("|") == std::string::npos)
			throw std::runtime_error("input file is not written in the good format. Stopping parsing there");
		std::cout << "token = |" << token << "|" << std::endl; // debug
		date_part = this->_trimWhitespaces(token.substr(0, token.find("|")));
		num_part = this->_trimWhitespaces(token.substr(token.find("|") + 1));
		try
		{
			Date		date(date_part); // trigger exception if not in good format
			Date		db_date = this->_getNearestDate(date);
			int			type;

			type = this->_checkNumericFormatValidity(num_part); // trigger exception if not in good format
			if (type == TYPE_FLOAT)
				std::cout << date << " => " << num_part << " = " << _computeConversion(_strToFloat(num_part), db_date);
			else
				std::cout << date << " => " << num_part << " = " << _computeConversion(atoi(num_part.c_str()), db_date);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		input_cpy.erase(0, pos + delimiter.length());
	}
}

/* input : trimmed str than contains a float or an integer with positive value
Check this, returns true if it is the case, false otherwise */
int	BitcoinExchange::_checkNumericFormatValidity(std::string num_part) // to test
{	
	if (num_part.size() < 1)
		throw std::runtime_error("");
	if (num_part.find_first_of('.') == std::string::npos) // case probably an int
	{		
		if (num_part.size() > 4)
			throw std::runtime_error("");
		for (std::size_t i = 0; i < num_part.size(); i++)
		{
			if (!std::isdigit(num_part[i]))
				throw std::runtime_error("");
		}
		if (atoi(num_part.c_str()) > 1000)
			throw std::runtime_error("");
	}
	else
		return (this->_checkFloatValidity(num_part));
	return (TYPE_INT);
}

int	BitcoinExchange::_checkFloatValidity(std::string num_part)
{
	std::string		decimal_part;
	std::string		int_part;

	// for the int part of the float
	int_part = num_part.find_first_of('.');
	if (int_part.size() > 4 || int_part.size() == 0)
		throw std::runtime_error("");
	for (std::size_t i = 0; i < int_part.size(); i++)
	{
		if (!std::isdigit(int_part[i]))
			throw std::runtime_error("");
	}
	if (atoi(int_part.c_str()) > 1000)
		throw std::runtime_error("");
	// for the decimal part of the float
	decimal_part = num_part.substr(num_part.find_first_of('.') + 1);
	std::cout << "decimal part = |" << decimal_part << "|" << std::endl;
	if (decimal_part.size() > 7 && decimal_part.size() == 0)
		throw std::runtime_error("");
	for (std::size_t i = 0; i < decimal_part.size(); i++)
	{
		if (!std::isdigit(decimal_part[i]))
			throw std::runtime_error("");
	}
	if (atoi(decimal_part.c_str()) > 8388607) // limit for the mantissa in float (23 bits)
		throw std::runtime_error("");
	return (TYPE_FLOAT);
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

			Date		next_date(key);

			this->_db_values.insert(std::pair<Date, std::string>(next_date, val));
		}
		this->_csv_str.erase(0, pos + delimiter.length());
		iter++;
	}
}

/* simple function to get the exchange rate of the nearest date provided */
float	BitcoinExchange::_getConversionRate(const Date date)
{
	std::string		float_str;
	std::map<Date, std::string>::iterator 	it_begin = this->_db_values.begin();
	std::map<Date, std::string>::iterator	it_end = this->_db_values.end();

	while (it_begin != it_end)
	{
		if (it_begin->first == date)
		{
			float_str = it_begin->second;
			break;
		}
		it_begin++;
	}
	return (this->_strToFloat(float_str));
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
const Date	BitcoinExchange::_getNearestDate(const Date date) // to test
{
	std::map<Date, std::string>::iterator	it_beg = this->_db_values.begin();
	std::map<Date, std::string>::iterator	it_end = this->_db_values.end();

	while (it_beg != it_end)
	{
		if (it_beg->first == date)
			return (it_beg->first);
		it_beg++;
	}
	it_beg = this->_db_values.begin();
	
	Date	prev(it_beg->first);
	
	while (it_beg != it_end)
	{
		if (it_beg != this->_db_values.begin() || prev < it_beg->first) // pb there
			return ((--it_beg)->first);
		prev = it_beg->first;
		it_beg++;
	}
	return ((--it_end)->first);// case this is the end
}
