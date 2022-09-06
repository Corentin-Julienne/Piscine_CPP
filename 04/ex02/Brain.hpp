/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:10:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:52:49 by cjulienn         ###   ########.fr       */
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

		std::string		getIdea(int index) const;
		void			setIdea(int index);
	
	private:
	
		std::string		_ideas[100];
};

#endif
