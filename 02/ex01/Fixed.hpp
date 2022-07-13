/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/13 15:17:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

	int					_fixed_point;
	static const int	_frac_bits = 8;
};

std::ostream&	operator<<(std::ostream &flux, const Fixed &ref);
