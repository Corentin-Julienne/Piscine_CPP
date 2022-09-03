/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:12:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 09:54:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>
#include <string>

struct Data
{
	std::string		name;
	int				randomNum;
	char			randomChar;
	float			randomFloat;
};

// protos from utils functions

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
