/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:10:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:52:28 by cjulienn         ###   ########.fr       */
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
		
		virtual void makeSound(void) const = 0;
		virtual std::string getIdeaInBrain(int index) const = 0;
	
	protected:

		std::string		_type;
};

#endif
