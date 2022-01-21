/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:20:43 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/18 15:59:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

#include <iostream>
#include <string>

class HumanB
{
	public:

	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon weapon);
	~HumanB();

	void			setWeapon(Weapon weapon);
	void			attack(void);

	private:

	std::string		_name;
	Weapon			*_weapon;
};

#endif
