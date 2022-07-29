/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:57:31 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/29 15:27:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

struct NotFoundException : public std::exception 
{
	const char * what() const throw()
	{
		return ("Element not found inside the container");
	}
};

template <typename T>
typename T::iterator easyfind(const T& ctner, int nb_to_find)
{
	typename T::iterator it = std::find(ctner.begin(), ctner.end(), nb_to_find);
	if (it != it.end())
		return (it);
	else
		throw NotFoundException();
}

#endif
