/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:50:22 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/13 16:02:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// basic constructor

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_dmgs(0)
{
	std::cout << "Constructor has been called !" << std::endl;
}

// destructor

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called !" << std::endl;
}

// copy constructor

ClapTrap::ClapTrap(const ClapTrap& original)
{
	_name = original._name;
	_hit_pts = original._hit_pts;
	_energy_pts = original._energy_pts;
	_attack_dmgs = original._attack_dmgs;
}

// overloading asssignation operator

ClapTrap&	ClapTrap::operator=(const ClapTrap& original)
{
	if (this != &original)
	{
		_name = original._name;
		_hit_pts = original._hit_pts;
		_energy_pts = original._energy_pts;
		_attack_dmgs = original._attack_dmgs;
	}
	return *this;
}

// other functions of the ClapTrap class

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attack_dmgs << " points of damage !!!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hit_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be attacked !" << std::endl;
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hit_pts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hit_pts == 0)
		std::cout << "ClapTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energy_pts--;
	this->_hit_pts += amount;
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " has used its reparaing ability to restore "
	<< amount << "hit points" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hit_pts << " hit points, and "
	<< this->_energy_pts << std::endl;
}
