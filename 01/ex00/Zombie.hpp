/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:33:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 16:49:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	public:

	Zombie(std::string name);
	~Zombie();
	void			announce(void);

	private:

	std::string		_z_name;
};

void 		randomChump(std::string name);
Zombie* 	newZombie(std::string name);

#endif
