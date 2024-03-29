/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:22:44 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 14:31:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// basic constructor

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmgs = 30;
	std::cout << "FragTrap Constructor called on " << this->_name << std::endl;
}

// advanced constructor

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmgs = 30;
	std::cout << "FragTrap Constructor called on " << this->_name << std::endl;
}

// basic destructor

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called on " << this->_name << std::endl;
}

// constructor by copy

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original._name)
{
	this->_hitPts = original._hitPts;
	this->_energyPts = original._energyPts;
	this->_attackDmgs = original._attackDmgs;
	std::cout << "FragTrap Constructor by copy called on " << this->_name << std::endl;
}

// overloading assignement operator

FragTrap&	FragTrap::operator=(const FragTrap& original)
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

// functions specific to FragTrap

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Hey, give me a high five mate !!!" << std::endl;
}

// masking functions from ClapTrap

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack ! ";
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	// feedback msg
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDmgs << " points of damage !!!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hitPts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot be attacked ! ";
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hitPts)
		this->_hitPts = 0;
	else
		this->_hitPts -= amount;
	// feedback msg
	std::cout << "FragTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "FragTrap " << this->_name << " has now " << this->_hitPts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hitPts == 0)
		std::cout << "FragTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energyPts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot repair itself ! ";
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energyPts--;
	this->_hitPts += amount;
	// feedback msg
	std::cout << "FragTrap " << this->_name << " has used its reparaing ability to restore "
	<< amount << "hit points" << std::endl;
	std::cout << "FragTrap " << this->_name << " has now " << this->_hitPts << " hit points, and "
	<< this->_energyPts << " energy points" << std::endl;
}
