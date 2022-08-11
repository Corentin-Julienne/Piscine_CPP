/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:43 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 17:28:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		~Animal();
		Animal(const Animal& original);

		Animal& operator=(const Animal& original);

		std::string	getType(void) const;
		
		virtual void makeSound(void) const;
	
	protected:

		std::string		_type;
};

#endif
