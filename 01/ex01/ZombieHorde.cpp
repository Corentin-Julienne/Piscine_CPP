/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:26:51 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 16:44:16 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int		i;

	Zombie *horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		horde[i].setZombieName(name);
		i++;
	}
	return (horde);
}
