/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:16:50 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 16:45:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void	leaks_tracker(void) // debugging tool
// {
// 	system("leaks Moar_brainz");
// }

int	main(void)
{
	Zombie		*the_walking_dead;
	int			i;

	// atexit(leaks_tracker); // debugging tool
	the_walking_dead = zombieHorde(12, "Rick");
	i = 0;
	while (i < 12)
	{
		the_walking_dead[i].announce();	
		i++;
	}
	i = 0;
	delete [] the_walking_dead;
	return (0);
}
