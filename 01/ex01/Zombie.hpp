/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:23:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/17 11:28:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie();

	Zombie*			newZombie(std::string name);
	void 			randomChump(std::string name);
	void			announce(void);
	
	private:

	std::string		_z_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
