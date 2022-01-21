/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:16:50 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/17 11:38:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*the_walking_dead;
	int			i;

	the_walking_dead = NULL;
	the_walking_dead = zombieHorde(12, "Rick");
	i = 0;
	while (i < 12)
	{
		the_walking_dead[i].announce();	
		i++;
	}
	i = 0;
	delete the_walking_dead;
	return (0);
}
