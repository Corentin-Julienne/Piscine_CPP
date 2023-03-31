/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:01 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/31 16:12:17 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <unistd.h>

void	Date::_verifyConstruction(void)
{
	std::cout << "-----------------------" << std::endl;
	std::cout << "years = " << this->years << ", months = " << this->months << " and days = " << this->days << std::endl;
	std::cout << "years = " << this->int_years << ", months = " << this->int_months << " and days = " << this->int_days << std::endl;
	std::cout << "-----------------------" << std::endl;
	sleep(1);
}

Date::Date(void) {}

Date::~Date() {}

Date::Date(std::string date_format)
{
	//std::cout << "|" << date_format << "| = size : " << date_format.size() << std::endl;
	
	this->_isDateFormatValid(date_format); // pb there
	/* data relative to date format */
	this->int_years = atoi(this->years.c_str());
	this->int_months = atoi(this->months.c_str());
	this->int_days = atoi(this->days.c_str());
	// debug
	//this->_verifyConstruction();
}

Date::Date(const Date& other) // OK
{
	this->years = other.years;
	this->months = other.months;
	this->days = other.days;
	this->int_years = other.int_years;
	this->int_months = other.int_months;
	this->int_days = other.int_days;
}

Date&	Date::operator=(const Date& other) // OK
{
	if (this != &other)
	{
		this->years = other.years;
		this->months = other.months;
		this->days = other.days;
		this->int_years = other.int_years;
		this->int_months = other.int_months;
		this->int_days = other.int_days;
	}
	return *this;
}

/* getters army */
const std::string&	Date::getYears(void) const { return this->years; } // OK
const std::string&	Date::getMonths(void) const { return this->months; } // OK
const std::string&	Date::getDays(void) const { return this->days; } // OK
const int&			Date::getIntYears(void) const { return this->int_years; } // OK
const int&			Date::getIntMonths(void) const { return this->int_months; } // OK
const int&			Date::getIntDays(void) const { return this->int_days; } // OK

std::string	Date::_rtnErrMsg(std::string format)
{
	std::string		res = "Error: bad input => " + format;
	
	return (res);
}

/* triggers an exception if format date format is not valid */
void	Date::_isDateFormatValid(std::string format) // to test
{
	/* verifying that general date format */
	if (format.size() != 10 || format[4] != '-' || format[7] != '-')
		std::cout << "problem case 1" << std::endl;
	//	throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	/* verifying that year is in good format/within adequate int range */
	this->years = format.substr(0, 4);
	for (std::size_t i = 0; i < this->years.size(); i++)
	{
		if (!std::isdigit(this->years[i]))
			std::cout << "problem case 2" << std::endl;
			//throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (atoi(this->years.c_str()) < 2009)
		throw std::runtime_error("problem case 3"); // add err msg
	/* verifying that month is in good/ format/within adequate int range */
	this->months = format.substr(5, 2);
	for (std::size_t i = 0; i < this->months.size(); i++)
	{
		if (!std::isdigit(this->months[i]))
			std::cout << "problem case 4" << std::endl;
			//throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (this->months[0] != '0' && atoi(this->months.c_str()) > 12)
		throw std::runtime_error("problem case 5"); // add err msg
	/* verifying that day is in good format/within adequate int range */
	this->days = format.substr(8);
	for (std::size_t i = 0; i < this->days.size(); i++)
	{
		if (!std::isdigit(this->days[i]))
			std::cout << "problem case 6" << std::endl;
			//throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (this->days[0] != '0' && atoi(this->days.c_str()) > 31)
		std::cout << "problem case 7" << std::endl;
		//throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
}

/* overloading comparison operators */

bool	Date::operator==(const Date& other) const
{	
	if (this->int_years != other.getIntYears())
		return (false);
	if (this->int_months != other.getIntMonths())
		return (false);
	if (this->int_days != other.getIntDays())
		return (false);
	return (true);
}

bool	Date::operator!=(const Date& other) const
{
	return (!(*this == other));
}

bool	Date::operator<(const Date& other) const
{
	if (this->int_years < other.getIntYears())
		return (true);
	if (this->int_months < other.getIntMonths())
		return (true);
	if (this->int_days < other.getIntDays())
		return (true);
	return (false);
}

bool	Date::operator>(const Date& other) const
{
	if (this->int_years > other.getIntYears())
		return (true);
	if (this->int_months > other.getIntMonths())
		return (true);
	if (this->int_days > other.getIntDays())
		return (true);
	return (false);
}

bool	Date::operator<=(const Date& other) const
{
	if (*this == other || *this < other)
		return (true);
	return (false);
}

bool	Date::operator>=(const Date& other) const
{
	if (*this == other || *this > other)
		return (true);
	return (false);
}

std::ostream&	operator<<(std::ostream& os, const Date& date) // OK
{
	os << date.getYears() << "-" << date.getMonths() << "-" << date.getDays();
	return (os);
}
