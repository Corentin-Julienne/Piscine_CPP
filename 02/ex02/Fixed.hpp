/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:09 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 10:51:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		// constructors and destructors
		
		Fixed(void);
		~Fixed();
		Fixed(const Fixed& original);
		Fixed(int num);
		Fixed(float num);

		Fixed&			operator=(const Fixed& original);

		// getters and setters
		
		int 			getRawBits(void) const;
		void 			setRawBits(int const raw);

		// converters
		
		int 			toInt(void) const;
		float 			toFloat(void) const;

		// static methods

		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

		// overloading arithmetic operators

		Fixed			operator+(const Fixed &scd);
		Fixed			operator-(const Fixed &scd);
		Fixed			operator*(const Fixed &scd);
		Fixed			operator/(const Fixed &scd);

		// overloading increment/decrement operators
		
		Fixed			operator++(void);   // ++a
		Fixed			operator--(void);   // --a
		Fixed			operator++(int); 	// a++
		Fixed			operator--(int); 	// a--

		// overloading comparison operators

		bool			operator==(const Fixed &scd);
		bool			operator!=(const Fixed &scd);
		bool			operator<(const Fixed &scd);
		bool			operator>(const Fixed &scd);
		bool			operator<=(const Fixed &scd);
		bool			operator>=(const Fixed &scd);

	private:

		int					_fixedPoint;
		static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &ref);

#endif
