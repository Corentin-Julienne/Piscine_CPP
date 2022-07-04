/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:33:59 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 16:43:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _z_name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_z_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_z_name << " BraiiiiiiinnnzzzZ..." <<  std::endl;
}
