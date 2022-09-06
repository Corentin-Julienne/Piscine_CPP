/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 10:34:08 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		Fixed(void);
		~Fixed();
		Fixed(const Fixed& original);

		Fixed&			operator=(const Fixed& original);
		
		Fixed(int num);
		Fixed(float num);
		
		int 			getRawBits(void) const;
		void 			setRawBits(int const raw);
		
		int 			toInt(void) const;
		float 			toFloat(void) const;
	
	private:

		int					_fixedPoint;
		static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &ref);

#endif
