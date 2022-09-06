/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:22:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:31:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor

ScavTrap::ScavTrap(void) : ClapTrap() 
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmgs = 20;
	std::cout << "ScavTrap Constructor has been called on " << this->_name << std::endl;
}

// constructor with name

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmgs = 20;
	std::cout << "ScavTrap Constructor has been called on " << this->_name << std::endl;
}

// destructor

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has been called on " << this->_name << std::endl;
}

// constructor by copy

ScavTrap::ScavTrap(const ScavTrap& original)
{
	this->_name = original._name;
	this->_hitPts = original._hitPts;
	this->_energyPts = original._energyPts;
	this->_attackDmgs = original._attackDmgs;
	std::cout << "ScavTrap Constructor (by copy) has been called on " << this->_name << std::endl;
}

// overloading assignement operator

ScavTrap&	ScavTrap::operator=(const ScavTrap& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_hitPts = original._hitPts;
		this->_energyPts = original._energyPts;
		this->_attackDmgs = original._attackDmgs;
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
	if (this->_hitPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack ! ";
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDmgs << " points of damage !!!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hitPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot be attacked ! ";
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hitPts)
		this->_hitPts = 0;
	else
		this->_hitPts -= amount;
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has now " << this->_hitPts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hitPts == 0)
		std::cout << "ScavTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energyPts--;
	this->_hitPts += amount;
	// feedback msg
	std::cout << "ScavTrap " << this->_name << " has used its reparaing ability to restore "
	<< amount << "hit points" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has now " << this->_hitPts << " hit points, and "
	<< this->_energyPts << " energy points" << std::endl;
}
