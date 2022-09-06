/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:36:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 10:30:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed(void);
		~Fixed();
		Fixed(const Fixed& original);
		
		Fixed&	operator=(const Fixed& original);
		
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:

		int					_fixedPoint;
		static const int	_fracBits = 8;
};

#endif
