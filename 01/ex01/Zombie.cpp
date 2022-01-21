/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:24:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/16 19:41:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	
}

Zombie::Zombie(std::string name) : _z_name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_z_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_z_name << " BraiiiiiiinnnzzzZ..." <<  std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *zombie_ptr = new Zombie(name);
	return (zombie_ptr);
}

void Zombie::randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();	
}
