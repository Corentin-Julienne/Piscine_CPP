/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 15:34:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	
	return (0);
}
