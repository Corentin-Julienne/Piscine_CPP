/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:06 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 12:28:49 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:

		Harl();
		~Harl();

		void complain( std::string level );
	
	private: // some member functions are also private in Harl class
	
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
