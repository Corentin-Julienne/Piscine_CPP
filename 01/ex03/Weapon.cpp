/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 20:13:12 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	
}

Weapon::~Weapon()
{
	
}

const std::string&	Weapon::getType(void)
{
	const std::string& ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
