/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:01 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 17:44:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(void) {}

Date::~Date() {}

Date::Date(std::string date_format)
{	
	this->_isDateFormatValid(date_format);
	/* data relative to date format */
	this->int_years = atoi(this->years.c_str());
	this->int_months = atoi(this->months.c_str());
	this->int_days = atoi(this->days.c_str());
}

Date::Date(const Date& other)
{
	this->years = other.years;
	this->months = other.months;
	this->days = other.days;
	this->int_years = other.int_years;
	this->int_months = other.int_months;
	this->int_days = other.int_days;
}

Date&	Date::operator=(const Date& other)
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
const std::string&	Date::getYears(void) const { return this->years; }
const std::string&	Date::getMonths(void) const { return this->months; }
const std::string&	Date::getDays(void) const { return this->days; }
const int&			Date::getIntYears(void) const { return this->int_years; }
const int&			Date::getIntMonths(void) const { return this->int_months; }
const int&			Date::getIntDays(void) const { return this->int_days; }

std::string	Date::_rtnErrMsg(std::string format)
{
	std::string		res = "Error: bad input => " + format;
	
	return (res);
}

/* triggers an exception if format date format is not valid */
void	Date::_isDateFormatValid(std::string format)
{
	/* verifying that general date format */
	if (format.size() != 10 || format[4] != '-' || format[7] != '-')
		throw std::runtime_error(this->_rtnErrMsg(format));
	/* verifying that year is in good format/within adequate int range */
	this->years = format.substr(0, 4);
	for (std::size_t i = 0; i < this->years.size(); i++)
	{
		if (!std::isdigit(this->years[i]))
			throw std::runtime_error(this->_rtnErrMsg(format));
	}
	/* verifying that month is in good format/within adequate int range */
	this->months = format.substr(5, 2);
	for (std::size_t i = 0; i < this->months.size(); i++)
	{
		if (!std::isdigit(this->months[i]))
			throw std::runtime_error(this->_rtnErrMsg(format));
	}
	if (this->months[0] != '0' && atoi(this->months.c_str()) > 12)
		throw std::runtime_error(this->_rtnErrMsg(format));
	/* verifying that day is in good format/within adequate int range */
	this->days = format.substr(8);
	for (std::size_t i = 0; i < this->days.size(); i++)
	{
		if (!std::isdigit(this->days[i]))
			throw std::runtime_error(this->_rtnErrMsg(format));
	}
	if (this->days[0] != '0' 
		&& !this->_isDayWithinRange(atoi(this->years.c_str()), atoi(this->months.c_str()), atoi(this->days.c_str())))
		throw std::runtime_error(this->_rtnErrMsg(format));
}

bool	Date::_isLeapYear(int year)
{
	 return (((year % 4) == 0 && (year % 100) != 0) || ((year % 400) == 0));
}

bool	Date::_isDayWithinRange(int year, int month, int day)
{	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{	
		if (day > 31)
			return (false);
	}
	else if (month == 2)
	{
		if (this->_isLeapYear(year) && day > 29)
			return (false);
		if (!this->_isLeapYear(year) && day > 28)
			return (false);
	}
	else // month with 30 days
	{
		if (day > 30)
			return (false);
	}
	return (true);
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
	if (this->int_years > other.getIntYears())
		return (false);
	if (this->int_months < other.getIntMonths())
		return (true);
	if (this->int_months > other.getIntMonths())
		return (false);
	if (this->int_days < other.getIntDays())
		return (true);
	return (false);
}

bool	Date::operator>(const Date& other) const
{
	if (this->int_years > other.getIntYears())
		return (true);
	if (this->int_years < other.getIntYears())
		return (false);
	if (this->int_months > other.getIntMonths())
		return (true);
	if (this->int_months < other.getIntMonths())
		return (false);
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

std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	os << date.getYears() << "-" << date.getMonths() << "-" << date.getDays();
	return (os);
}

void	Date::_verifyConstruction(void)
{
	std::cout << "-----------------------" << std::endl;
	std::cout << "years = " << this->years << ", months = " << this->months << " and days = " << this->days << std::endl;
	std::cout << "years = " << this->int_years << ", months = " << this->int_months << " and days = " << this->int_days << std::endl;
	std::cout << "-----------------------" << std::endl;
}
