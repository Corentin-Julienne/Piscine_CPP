/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:39:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/27 17:13:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// return a uinptr for serialization purpose (transform a ptr to Data struct)

uintptr_t	serialize(Data* ptr)
{
	uintptr_t		res;

	res = reinterpret_cast <uintptr_t> (ptr);
	return (res);
}

// return a ptr to a Data struct (transform a uinptr_t ptr to a ptr to a previously saved Data object)

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *> (raw));
}
