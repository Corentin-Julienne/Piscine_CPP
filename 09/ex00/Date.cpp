/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:01 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:32 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(void) {}

Date::~Date() {}

Date::Date(std::string date_format) // to test
{
	/* data relative to date format */
	this->_isDateFormatValid(date_format);
	this->years = date_format.substr(0, 4);
	this->int_years = atoi(this->years.c_str());
	this->months = date_format.substr(5, 2);
	this->int_months = atoi(this->months.c_str());
	this->days = date_format.substr(8);
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
void	Date::_isDateFormatValid(std::string format) // to test
{
	/* verifying that general date format */
	if (format.size() != 10 || format[4] != '-' || format[7] != '-')
		throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	/* verifying that year is in good format/within adequate int range */
	this->years = format.substr(0, 4);
	std::cout << "year = |" << this->years << "|" << std::endl;
	for (std::size_t i = 0; i < this->years.size(); i++)
	{
		if (!std::isdigit(this->years[i]))
			throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (atoi(this->years.c_str()) < 2011)
		throw std::runtime_error(""); // add err msg
	/* verifying that month is in good/ format/within adequate int range */
	this->months = format.substr(5, 2);
	std::cout << "month = |" << this->months << "|" << std::endl;
	for (std::size_t i = 0; i < this->months.size(); i++)
	{
		if (!std::isdigit(this->months[i]))
			throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (this->months[0] != '0' && atoi(this->months.c_str()) > 12)
		throw std::runtime_error(""); // add err msg
	/* verifying that day is in good format/within adequate int range */
	this->days = format.substr(8);
	std::cout << "day = |" << this->days << "|" << std::endl;
	for (std::size_t i = 0; i < this->days.size(); i++)
	{
		if (!std::isdigit(this->days[i]))
			throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
	}
	if (this->days[0] != '0' && atoi(this->days.c_str()) > 31)
		throw std::runtime_error(this->_rtnErrMsg(format)); // add err msg
}

std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	std::cout << date.getYears() << "_" << date.getMonths() << "-" << date.getDays();
}

bool	operator==(const Date& first, const Date& second)
{
	if (first.getIntYears() != second.getIntYears())
		return (false);
	if (first.getIntMonths() != second.getIntMonths())
		return (false);
	if (first.getIntDays() != second.getIntDays())
		return (false);
	return (true);
}

bool	operator!=(const Date& first, const Date& second)
{
	return (!(first == second));
}

bool	operator<(const Date& first, const Date& second)
{
	if (first == second || first.getIntYears() > second.getIntYears())
		return (false);
	if (first.getIntMonths() > second.getIntMonths())
		return (false);
	if (first.getIntDays() > second.getIntDays())
		return (false);
	return (true);
}

bool	operator>(const Date& first, const Date& second)
{
	return (!(first < second));
}

bool	operator<=(const Date& first, const Date& second)
{
	if (first == second || first < second)
		return (true);
	return (false);
}

bool	operator>=(const Date& first, const Date& second)
{
	if (first == second || first > second)
		return (true);
	return (false);
}
