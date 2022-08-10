/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 17:10:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// constructor

Weapon::Weapon(std::string type) : _type(type) {}

// destructor

Weapon::~Weapon() {}

// getter and setter

const std::string&	Weapon::getType(void)
{
	const std::string& ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
