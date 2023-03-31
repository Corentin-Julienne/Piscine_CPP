/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:03 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/31 12:42:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

#define DB		1
#define INPUT	2

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

	private:

		Date(void);

		void					_isDateFormatValid(std::string format);
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

bool	operator==(const Date& first, const Date& second);
bool	operator!=(const Date& first, const Date& second);
bool	operator<(const Date& first, const Date& second);
bool	operator>(const Date& first, const Date& second);
bool	operator<=(const Date& first, const Date& second);
bool	operator>=(const Date& first, const Date& second);

#endif
