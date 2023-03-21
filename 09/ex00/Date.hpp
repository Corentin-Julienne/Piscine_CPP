/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:43:03 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/21 14:02:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

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
};

std::ostream&	operator<<(std::ostream& os, const Date& date);

bool	operator==(const Date& first, const Date& second);
bool	operator!=(const Date& first, const Date& second);
bool	operator<(const Date& first, const Date& second);
bool	operator>(const Date& first, const Date& second);
bool	operator<=(const Date& first, const Date& second);
bool	operator>=(const Date& first, const Date& second);
