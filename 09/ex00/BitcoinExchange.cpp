/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:00 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/05 10:56:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(char *file_path) 
{	
	this->_openFiles(file_path);
	this->_extractDatabase();
	this->_printContent();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_csv_str = other._csv_str;
	this->_input_str = other._input_str;
	this->_db_values = other._db_values;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_csv_str = other._csv_str;
		this->_input_str = other._input_str;
		this->_db_values = other._db_values;
	}
	return *this;
}

/* GETTERS AND SETTERS */

// private helper functions

/* try to display */
void	BitcoinExchange::_printContent(void)
{
	std::size_t		pos;
	std::size_t		iter = 0;
	std::string		token;
	std::string		date_part;
	std::string		num_part;

	while (!this->_input_str.empty())
	{
		pos = this->_input_str.find('\n');
		token = this->_input_str.substr(0, pos);
		if (this->_input_str.find('\n') == std::string::npos)
			this->_input_str.clear();
		else
			this->_input_str.erase(0, pos + 1);
		if (iter == 0 && !this->_checkHeader(token))
			return ;
		if (token.find("|") == std::string::npos)
		{
			std::cout << "Error: bad input => " << token << std::endl;
			iter++;
			continue ;
		}
		date_part = this->_trimWhitespaces(token.substr(0, token.find("|")));
		num_part = this->_trimWhitespaces(token.substr(token.find("|") + 1));
		if (iter)
		{
			try
			{
				Date		date(date_part);
				Date		min("2009-01-02");

				if (date < min)
					throw std::runtime_error("Error: date provided is inferior to the creation of Bitcoin");
				
				Date		db_date = this->_getNearestDate(date);
				int			type;

				type = this->_checkNumericFormatValidity(num_part);
				if (type == TYPE_FLOAT)
					std::cout << date << " => " << num_part << " = " << _computeConversion(_strToFloat(num_part), db_date);
				else
					std::cout << date << " => " << num_part << " = " << _computeConversion(atoi(num_part.c_str()), db_date);
				std::cout << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		iter++;
	}
}

bool	BitcoinExchange::_checkHeader(std::string header)
{
	if (header.find("|") == std::string::npos)
	{
		std::cout << "Header format is not respected. Stopping parsing there" << std::endl;
		return (false);
	}
	
	std::string	first = this->_trimWhitespaces(header.substr(0, header.find("|")));
	std::string second = this->_trimWhitespaces(header.substr(header.find("|") + 1));

	if (first.compare("date") || second.compare("value"))
	{
		std::cout << "Header format is not respected. Stopping parsing there" << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::_extractDatabase(void)
{
	std::size_t			pos;
	std::size_t			iter = 0;
	std::string			token;
	std::string			key;
	std::string			val;


	while ((pos = this->_csv_str.find('\n')) != std::string::npos)
	{
		token = this->_csv_str.substr(0, pos);
		if (iter)
		{
			key = token.substr(0, token.find_first_of(','));
			val = token.substr(token.find_first_of(',') + 1);
			try
			{				
				Date		next_date(key);
				
				std::pair<std::map<Date, std::string>::iterator, bool> result;
				
				result = this->_db_values.insert(std::make_pair<Date, std::string>(next_date, val));
				if (!result.second)
					std::cout << "duplicated key !" << std::endl; // help debugging
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		this->_csv_str.erase(0, pos + 1);
		iter++;
	}
}

/* open input file and database */
void	BitcoinExchange::_openFiles(char *file_path)
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

	input_file.close();
	csv_file.close();
}

float	BitcoinExchange::_computeConversion(float num, const Date date)
{
	float				exchange_rate = this->_getConversionRate(date);
	float				res = num * exchange_rate;

	std::cout.precision(2);
	std::cout << std::fixed;
	return (res);
}

float	BitcoinExchange::_computeConversion(int num, const Date date)
{
	float				float_num = static_cast<float>(num);
	float				exchange_rate = this->_getConversionRate(date);
	float				res = float_num * exchange_rate;

	std::cout.precision(2);
	std::cout << std::fixed;
	return (res);
}

/* input : trimmed str than contains a float or an integer with positive value
Check this, returns true if it is the case, false otherwise */
int	BitcoinExchange::_checkNumericFormatValidity(std::string num_part) // to test
{	
	bool			minus_sign = false;
	std::size_t		is_dig = 0;
	
	if (num_part.size() < 1)
		throw std::runtime_error("Error: not a number.");
	if (num_part.find_first_of('.') == std::string::npos) // case int
	{		
		if (num_part.size() > 4)
			throw std::runtime_error("Error: too large a number.");			
		for (std::size_t i = 0; i < num_part.size(); i++)
		{
			if (i == 0 && num_part[i] == '-')
				minus_sign = true;
			else if (std::isdigit(num_part[i]))
				is_dig++;
		}
		if (minus_sign && is_dig == num_part.size() - 1)
			throw std::runtime_error("Error: not a positive number.");
		for (std::size_t i = 0; i < num_part.size(); i++)
		{
			if (!std::isdigit(num_part[i]))
				throw std::runtime_error("Error: not a number.");
		}
		if (atoi(num_part.c_str()) > 1000)
			throw std::runtime_error("Error: too large a number.");
	}
	else
		return (this->_checkFloatValidity(num_part));
	return (TYPE_INT);
}

int	BitcoinExchange::_checkFloatValidity(std::string num_part)
{
	std::string		decimal_part;
	std::string		int_part;
	bool			minus_sign = false;
	std::size_t		is_dig = 0;

	/* for the int part of the float */
	int_part = num_part.substr(0, num_part.find_first_of('.'));
	if (int_part.size() > 4 || int_part.size() == 0)
		throw std::runtime_error("Error: too large a number.");
	for (std::size_t i = 0; i < int_part.size(); i++)
	{
		if (i == 0 && int_part[i] == '-')
			minus_sign = true;
		else if (std::isdigit(int_part[i]))
			is_dig++;
	}
	if (minus_sign && is_dig == int_part.size() - 1)
		throw std::runtime_error("Error: not a positive number.");
	for (std::size_t i = 0; i < int_part.size(); i++)
	{
		if (!std::isdigit(int_part[i]))
			throw std::runtime_error("Error: not a number.");
	}
	if (atoi(int_part.c_str()) > 1000)
		throw std::runtime_error("Error: too large a number.");
	/* for the decimal part of the float */
	decimal_part = num_part.substr(num_part.find_first_of('.') + 1);
	for (std::size_t i = 0; i < decimal_part.size(); i++)
	{
		if (!std::isdigit(decimal_part[i]))
			throw std::runtime_error("Error: not a number.");
	}
	return (TYPE_FLOAT);
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

/* trim whitespaces */
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
const Date	BitcoinExchange::_getNearestDate(const Date date)
{
	std::map<Date, std::string>::reverse_iterator	it = this->_db_values.rbegin();

	while (it != this->_db_values.rend())
	{
		/* case the date is the exact date */
		if (date >= it->first)
			return (it->first);
		it++;
	}
	return ((--it)->first); // case date is the more recent than every entry in DB
}

/* debug functions */
void	BitcoinExchange::_displayDatabase(void)
{
	std::map<Date, std::string>::iterator	it = this->_db_values.begin();
	
	while (it != this->_db_values.end())
	{
		std::cout << it->first << "," << it->second << std::endl;
		it++;
	}
	std::cout << "size = " << this->_db_values.size() << " (should be 1612)" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}
