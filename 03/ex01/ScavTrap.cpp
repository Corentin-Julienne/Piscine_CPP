/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:08:23 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/14 12:31:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor

ScavTrap::ScavTrap(void) : ClapTrap() 
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmgs = 20;
	std::cout << "ScavTrap Constructor has been called !" << std::endl;
}

// constructor with name

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmgs = 20;
	std::cout << "ScavTrap Constructor has been called !" << std::endl;
}

// destructor

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has been called !" << std::endl;
}

// constructor by copy

ScavTrap::ScavTrap(const ScavTrap& original)
{
	this->_name = original._name;
	this->_hit_pts = original._hit_pts;
	this->_energy_pts = original._energy_pts;
	this->_attack_dmgs = original._attack_dmgs;
	std::cout << "ScavTrap Constructor (by copy) has been called !" << std::endl;
}

// overloading assignement operator

ScavTrap&	ScavTrap::operator=(const ScavTrap& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_hit_pts = original._hit_pts;
		this->_energy_pts = original._energy_pts;
		this->_attack_dmgs = original._attack_dmgs;
	}
	return *this;
}

// others functions

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper Mode" << std::endl;
}

// other functions of the ClapTrap class (using masking feature of c++)

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attack_dmgs << " points of damage !!!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hit_pts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot be attacked !" << std::endl;
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has now " << this->_hit_pts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hit_pts == 0)
		std::cout << "ScavTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energy_pts--;
	this->_hit_pts += amount;
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " has used its reparaing ability to restore "
	<< amount << "hit points" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has now " << this->_hit_pts << " hit points, and "
	<< this->_energy_pts << std::endl;
}
