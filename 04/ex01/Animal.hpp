/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:34:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 19:58:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

#include <string>
#include <iostream>

class Animal
{
	public:

		Animal(void);
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& original);

		Animal& operator=(const Animal& original);

		std::string	getType(void) const;
		
		virtual void		makeSound(void) const;
		virtual std::string getIdeaInBrain(int index) const;
	
	protected:

		std::string		_type;
};

#endif
