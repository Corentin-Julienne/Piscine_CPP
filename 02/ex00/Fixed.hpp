/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/20 13:37:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& ref);
	
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	Fixed&	operator=(const Fixed& ref);

	private:

	int					_fixed_point;
	static const int	_frac_bits = 8;
};
