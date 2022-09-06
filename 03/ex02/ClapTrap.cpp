/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:22:39 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:31:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// basic constructor

ClapTrap::ClapTrap(void) : _name("Unit_01"), _hitPts(10), _energyPts(10), _attackDmgs(0)
{
	std::cout << "ClapTrap Constructor has been called on " << this->_name << std::endl;
}

// constructor with name

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmgs(0)
{
	std::cout << "ClapTrap Constructor has been called on " << this->_name << std::endl;
}

// destructor

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor has been called on " << this->_name << std::endl;
}

// copy constructor

ClapTrap::ClapTrap(const ClapTrap& original) : 
_name(original._name), _hitPts(original._hitPts),
_energyPts(original._energyPts), _attackDmgs(original._attackDmgs) 
{
	std::cout << "ClapTrap Constructor (by copy) has been called on " << this->_name <<std::endl;
}

// overloading asssignation operator

ClapTrap&	ClapTrap::operator=(const ClapTrap& original)
{
	if (this != &original)
	{
		_name = original._name;
		_hitPts = original._hitPts;
		_energyPts = original._energyPts;
		_attackDmgs = original._attackDmgs;
	}
	return *this;
}

// other functions of the ClapTrap class

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack !";
		std::cout << " Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energyPts--;
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDmgs << " points of damage !!!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hitPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be attacked !" << std::endl;
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hitPts)
		this->_hitPts = 0;
	else
		this->_hitPts -= amount;
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hitPts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hitPts == 0)
		std::cout << "ClapTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energyPts--;
	this->_hitPts += amount;
	if (this->_hitPts > 10)
		this->_hitPts = 10;
	// feedback msg
	std::cout << "ClapTrap " << this->_name << " has used its reparaing ability to restore at most "
	<< amount << " hit points" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hitPts << " hit points, and "
	<< this->_energyPts << " energy points" << std::endl;
}
