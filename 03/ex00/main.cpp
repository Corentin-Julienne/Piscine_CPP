/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:50:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 14:58:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
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
	return (0);
}
