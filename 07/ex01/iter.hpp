/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:41:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/28 15:27:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

// typename A refers to the first param, S for the second
template <typename A>
void	iter(A *arr_addr, unsigned int size, void (*f)(const A&, unsigned int))
{
	for (unsigned int i = 0; i < size; i++)
	{
		(*f)(arr_addr[i], i);
	}
}

// function template used by iter
template <typename A>
void	displayer(const A& arr_addr, unsigned int i)
{
	std::cout << "Array of index " << i << " contains the value " << arr_addr << std::endl;
}

#endif
