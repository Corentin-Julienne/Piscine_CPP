/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:50:24 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/13 15:28:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& original);
		
		ClapTrap&	operator=(const ClapTrap& original);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int 	_hit_pts;
		unsigned int	_energy_pts;
		unsigned int  	_attack_dmgs;
};

#endif
