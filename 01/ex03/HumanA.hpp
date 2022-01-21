/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:19 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/18 12:26:17 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.hpp"

#include <iostream>
#include <string>

class HumanA
{
	public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void				attack(void);
	
	private:

	std::string			_name;
	Weapon&				_weapon;
};

#endif
