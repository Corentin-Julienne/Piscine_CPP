/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:57:31 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 10:39:58 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

struct NotFoundException : public std::exception 
{
	const char * what() const throw()
	{
		return ("Element not found inside the container");
	}
};

template <typename T>
typename T::iterator easyfind(T& ctner, int nb_to_find)
{
	typename T::iterator it = std::find(ctner.begin(), ctner.end(), nb_to_find);
	if (it != ctner.end())
		return (it);
	else
		throw NotFoundException();
}

#endif
