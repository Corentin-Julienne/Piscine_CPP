/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 20:27:42 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) :_name(name)
{
	this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name) 
{
	this->_weapon = &weapon;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his ";
	if (this->_weapon != NULL)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "super middle kick (aiming at the balls !!!)" << std::endl;
}
