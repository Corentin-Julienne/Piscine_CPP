/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 14:58:28 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
	
		Brain(void);
		~Brain();
		Brain(const Brain& original);
		
		Brain& operator=(const Brain &original);
	
	private:
	
		std::string		_ideas[100];
};

#endif
