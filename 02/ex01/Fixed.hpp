/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/30 12:18:19 by cjulienn         ###   ########.fr       */
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
	~Fixed(void);
	Fixed(const Fixed& original);
	Fixed(int num);
	Fixed(float num);
	
	int 			getRawBits(void) const;
	void 			setRawBits(int const raw);
	Fixed&			operator=(const Fixed& original);
	int 			toInt(void) const;
	float 			toFloat(void) const;
	
	private:

	int					_fixedPoint;
	static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &ref);

#endif
