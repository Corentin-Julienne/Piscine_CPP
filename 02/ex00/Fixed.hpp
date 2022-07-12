/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/12 16:44:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& original);
	Fixed&	operator=(const Fixed& original);
	
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);

	private:

	int					_fixed_point;
	static const int	_frac_bits = 8;
};
