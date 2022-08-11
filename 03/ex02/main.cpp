/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:22:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 16:01:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	// old ClapTrap Tests
	
	ClapTrap	alpha("Unit Alpha");
	ClapTrap	bravo("Unit Bravo");

	// some basic tests
	alpha.attack("Unit Bravo");
	bravo.takeDamage(0);
	bravo.beRepaired(12);
	// loosing energy points 
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	alpha.attack("Unit Bravo");
	// checkcing that error msg when try to attack or repair (no energy points)
	alpha.attack("Unit Bravo");
	alpha.beRepaired(1);
	// put hit points to 0 and check if can repair itself (should display error msg)
	bravo.takeDamage(11);
	bravo.beRepaired(3); 

	// new testing procedure

	ScavTrap	charlie("Unit Charlie");
	ScavTrap	delta("Unit Delta");
	ScavTrap	echo("Unit Echo");
	
	// testing guard gate functions

	charlie.guardGate();
	delta.guardGate();

	// testing attacks and testing reparation

	charlie.attack("Unit Delta");
	delta.takeDamage(20);
	delta.beRepaired(20);

	// destroying unit echo

	charlie.attack("Unit Echo");
	echo.takeDamage(20);
	charlie.attack("Unit Echo");
	echo.takeDamage(20);
	charlie.attack("Unit Echo");
	echo.takeDamage(20);
	delta.attack("Unit Echo");
	echo.takeDamage(20);
	delta.attack("Unit Echo");
	echo.takeDamage(20); // should print a "Unit echo has been destroyed"

	// try to repair echo (should fail)
	echo.beRepaired(100);
	// try to make echo attacking (should fail)
	echo.attack("Unit Delta");

	// TESTS FOR EX02

	std::cout << "----------------------------------------------------------------" << std::endl;
	
	FragTrap	foxtrot("Unit Foxtrot");
	FragTrap	golf("Unit Golf");
	FragTrap	hotel("Unit Hotel");
	
	// testing high five function	
	foxtrot.highFivesGuys();
	golf.highFivesGuys();

	// testing attack and reparation
	foxtrot.attack("Unit Golf");
	golf.takeDamage(30);
	golf.beRepaired(30);
	
	// destroying unit hotel
	foxtrot.attack("Unit Hotel");
	hotel.takeDamage(30);
	foxtrot.attack("Unit Hotel");
	hotel.takeDamage(30);
	charlie.attack("Unit Hotel");
	hotel.takeDamage(20);
	charlie.attack("Unit Hotel");
	hotel.takeDamage(20);
	// try to repair hotel (should fail)
	hotel.beRepaired(40);
	// try to make hotel attacking (should fail)
	hotel.attack("Unit Foxtrot");
	
	return (0);
}
