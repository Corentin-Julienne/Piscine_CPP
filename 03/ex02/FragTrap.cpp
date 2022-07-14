/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:22:44 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/14 12:50:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// basic constructor

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmgs = 30;
	std::cout << "FragTrap Constructor called !" << std::endl;
}

// advanced constructor

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmgs = 30;
	std::cout << "FragTrap Constructor called !" << std::endl;
}

// basic destructor

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called !" << std::endl;
}

// constructor by copy

FragTrap::FragTrap(const FragTrap& original)
{
	this->_name = original._name;
	this->_hit_pts = original._hit_pts;
	this->_energy_pts = original._energy_pts;
	this->_attack_dmgs = original._attack_dmgs;
	std::cout << "FragTrap Constructor by copy called !" << std::endl;
}

// overloading assignement operator

FragTrap&	FragTrap::operator=(const FragTrap& original)
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

// functions specific to FragTrap

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Hey, give me a high five mate !!!" << std::endl;
}

// masking functions from ClapTrap

void	FragTrap::attack(const std::string& target)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	// feedback msg
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attack_dmgs << " points of damage !!!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	// case ClapTrap already detroyed
	if (this->_hit_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot be attacked !" << std::endl;
		std::cout << "Indeed, it has been already destroyed (hit points equal to 0) " << std::endl;	
		return ;
	}
	if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	// feedback msg
	std::cout << "FragTrap " << this->_name << " has taken " << amount 
	<< " points of damage" << std::endl;
	std::cout << "FragTrap " << this->_name << " has now " << this->_hit_pts << " hit points" << std::endl;
	// case ClapTrap have 0 hit points
	if (this->_hit_pts == 0)
		std::cout << "FragTrap " << this->_name << " has been destroyed !" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has already been destroyed (hit points equal to 0)" << std::endl;
		return ;
	}
	else if (this->_energy_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot repair itself !" << std::endl;
		std::cout << "Indeed, it has no energy points" << std::endl;
		return ;
	}
	this->_energy_pts--;
	this->_hit_pts += amount;
	// feedback msg
	std::cout << "FragTrap " << this->_name << " has used its reparaing ability to restore "
	<< amount << "hit points" << std::endl;
	std::cout << "FragTrap " << this->_name << " has now " << this->_hit_pts << " hit points, and "
	<< this->_energy_pts << std::endl;
}
