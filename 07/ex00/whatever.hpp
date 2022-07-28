/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:20:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/28 11:37:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& val_1, T& val_2)
{
	T	tmp;
	
	tmp = val_1;
	val_1 = val_2;
	val_2 = tmp;
}

template <typename T>
T min(const T& val_1, const T& val_2)
{
	if (val_1 < val_2)
		return (val_1);
	else
		return (val_2);
}

template <typename T>
T max(const T& val_1, const T& val_2)
{
	if (val_1 > val_2)
		return (val_1);
	else
		return (val_2);
}

#endif
