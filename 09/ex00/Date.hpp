/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:03 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 17:25:10 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

class BitcoinExchange;

class Date
{
	public:
	
		Date(std::string date_format);
		~Date();
		Date(const Date& other);
		Date&	operator=(const Date& other);

		const std::string&	getYears(void) const;
		const std::string&	getMonths(void) const;
		const std::string&	getDays(void) const;
		const int&			getIntYears(void) const;
		const int&			getIntMonths(void) const;
		const int&			getIntDays(void) const;

		bool	operator==(const Date& other) const;
		bool	operator!=(const Date& other) const;
		bool	operator<(const Date& other) const;
		bool	operator>(const Date& other) const;
		bool	operator<=(const Date& other) const;
		bool	operator>=(const Date& other) const;

	private:

		Date(void);

		void					_isDateFormatValid(std::string format);
		bool					_isDayWithinRange(int year, int month, int day);
		bool					_isLeapYear(int year);
		std::string				_rtnErrMsg(std::string format);
	
		std::string				years;
		std::string				months;
		std::string				days;
		int						int_years;
		int						int_months;
		int						int_days;

		/* debug */
		void					_verifyConstruction(void);
};

std::ostream&	operator<<(std::ostream& os, const Date& date);

#endif
